#include "NetworkManager.h"
#include <typeinfo>
#include "TimerManager.h"
#include <functional>
#include "TimeUtils.h"

NetworkManager* NetworkManager::m_networkManagerPtr = nullptr;

NetworkManager* NetworkManager::getNetworkManager()
{
	if (nullptr == m_networkManagerPtr)
	{

		m_networkManagerPtr = new NetworkManager();

	}
	return m_networkManagerPtr;

}


NetworkManager::NetworkManager() :
	Manager(typeid(NetworkManager).name()),
	m_clients(),
	m_servers(),
	m_sockSet(),
	m_newClients(),
	m_newServers()
{
	FD_ZERO(&m_sockSet);

	// Register timer slot
	TimerManager* timerMgr = TimerManager::getTimerManager();
	SocketMgmtTimer_t* tmrMsg = new SocketMgmtTimer_t(true, SOCKET_SERVICE_PERIOD);
	timerMgr->Add(tmrMsg, &m_location);
	Slot* sl = new Slot(this);
	sl->registerSlot(std::bind(&NetworkManager::connectionMaintenance, this, std::placeholders::_1));
	addSlot(*sl, *tmrMsg);
}


NetworkManager::~NetworkManager()
{
}

void NetworkManager::Start()
{


}

bool NetworkManager::Run()
{
	bool ret = true;
	//TODO


	initNewSockets();

	timeval timeOut;
	timeOut.tv_sec = 0;
	timeOut.tv_usec = 10000;
	
	fd_set readFd(m_sockSet);

	int32_t numSelected = select(FD_SETSIZE, &readFd, nullptr, nullptr, &timeOut);

	if (numSelected < 0)
	{
		if (readFd.fd_count == 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1000 * 2));
			std::cout << "false err" << std::endl;
		}
		else
		{
			// An error has occurred :(
			std::cout << "select err "<< GetLastError() << std::endl;
		}
	}
	else if (0 == numSelected)
	{
		// Continue to loop...just timed out
	}
	else
	{
		int32_t numServiced = 0;

		// A socket can be read on.

		// Loop through each client and service those sockets that have been set in the fd_set
		ClientVec_t::iterator clientIt = m_clients.begin();
		const ClientVec_t::iterator clientEndIt = m_clients.end();
		while (clientEndIt != clientIt && numServiced < numSelected)
		{
			// Get socket descrip
			int32_t fd = (*clientIt)->getSocketDesciptor();
			// Check if socket descrip has been set in the fd_set
			if (FD_ISSET(fd, &readFd))
			{
				serviceClient(*clientIt);
				//FD_CLR(fd, &m_sockSet);
				numServiced++;
			}
			clientIt++;
		}

		// Loop through each server and service it and all of its subsequent client connections (that are set in the fd_set)
		ServerVec_t::iterator serverIt = m_servers.begin();
		ServerVec_t::iterator serverEndIt = m_servers.end();
		while (serverEndIt != serverIt && numServiced < numSelected)
		{
			// Get socket descrip
			int32_t fd = (*serverIt)->getSocketDesciptor();
			// Check if socket descrip has been set in the fd_set
			if (FD_ISSET(fd, &readFd))
			{
				serviceServer(*serverIt, (*serverIt)->getSocketDesciptor(), (*serverIt)->DEFAULT_CONNECTION);
				//FD_CLR(fd, &m_sockSet);
				numServiced++;
			}
			IpServer::SockAddrVec_t::iterator connIt = (*serverIt)->m_clientAddrVec.begin();
			IpServer::SockAddrVec_t::iterator connEndIt = (*serverIt)->m_clientAddrVec.end();
			while (connEndIt != connIt)
			{
				if (FD_ISSET((*connIt).sd, &readFd))
				{
					serviceServer(*serverIt, (*connIt).sd, *connIt);
					//FD_CLR((*connIt).sd, &m_sockSet);
					numServiced++;
				}
				connIt++;


			}

			serverIt++;
		}
	}


	return ret;
}


void NetworkManager::Stop()
{
	// Loop through all clients, close each socket
	ClientVec_t::iterator it = m_clients.begin();
	ClientVec_t::iterator endIt = m_clients.end();

	for (; it != endIt; it++)
	{
		(*it)->closeSocket((*it)->getSocketDesciptor());
		(*it)->onDisconnect();
	}

	// Loop through all servers, close all sockets associated with it.
	ServerVec_t::iterator it2 = m_servers.begin();
	ServerVec_t::iterator endIt2 = m_servers.end();

	for (; it2 != endIt2; it2++)
	{
		(*it2)->closeSocket((*it2)->getSocketDesciptor());

		// Loop through each connection for server and run the onDisconnect virtual function
		// for each of them. 
		IpServer::SockAddrVec_t::iterator connIt = (*it2)->m_clientAddrVec.begin();
		IpServer::SockAddrVec_t::iterator connEndIt = (*it2)->m_clientAddrVec.end();
		for (; connIt < connEndIt; connIt++)
		{
			(*it2)->onDisconnect((*connIt));
		}
	}
}

void NetworkManager::checkClientHealth(IpClient* client)
{
	//TODO add some sort of error logging
	if (nullptr != client)
	{
		switch (client->getStatus())
		{
		case IpClient::ClientStatus_t::UNKNOWN:
		case IpClient::ClientStatus_t::NOT_CONNECTED:
		case IpClient::ClientStatus_t::CONNECTING:
			client->startClient();
			break;

		case IpClient::ClientStatus_t::CONNECTED:
		{
			std::string msg(client->getHeartBeatMsg());
			if (msg.length() != client->sendData(msg))
			{
				// Connection is broken, could not send heartbeat msg
				// Need to demote to NOT_CONNECTED
				client->setStatus(IpClient::ClientStatus_t::NOT_CONNECTED);
			}
			else
			{
				// Connection is fine
			}
			break;
		}
		default:
			break;
		}
	}
}

void NetworkManager::checkServerHealth(IpServer* server)
{
	//TODO
	if (nullptr != server)
	{


		switch (server->getStatus())
		{
		case IpServer::ServerStatus_t::UNKNOWN:
		case IpServer::ServerStatus_t::NOT_CONNECTED:
			server->startServer();
			break;
		default:
			break;
		}



		std::string msg(server->getHeartBeatMsg());



		IpServer::SockAddrVec_t::iterator it = server->m_clientAddrVec.begin();
		IpServer::SockAddrVec_t::iterator endIt = server->m_clientAddrVec.end();
		for (; it != endIt; it++)
		{

			int32_t sd = (*it).sd;
			if (msg.length() != server->sendData(msg, sd))
			{
				// Connection is broken, could not send heartbeat msg
				// Need to demote to NOT_CONNECTED
				(*it).stat = IpServer::ConnStatus_t::NOT_CONNECTED;
				server->onDisconnect((*it));

				server->handleBrokenConn(sd);

			}
			else
			{
				// Connection is fine
			}

		}
	}
}

bool NetworkManager::RegisterClient(IpClient* client)
{
	bool ret = true;
	if (nullptr != client)
	{
		// Add to list of client handles
		m_newClients.push_back(client);

		ret = true;
	}
	else
	{
		ret = false;
	}
	// TODO check if successfully added to vec
	return ret;
}
bool NetworkManager::RegisterServer(IpServer* server)
{
	bool ret = true;

	if (nullptr != server)
	{
		m_newServers.push_back(server);
		ret = true;
		
	}
	else
	{
		ret = false;
	}
	return ret;
}

bool NetworkManager::RemoveClient(IpClient* client)
{
	bool ret = false;

	// Loop through entire client vector until the correct client is
	// found. 
	ClientVec_t::iterator it = m_clients.begin();
	ClientVec_t::iterator endIt = m_clients.end();
	int32_t fd = client->getSocketDesciptor();
	for (; it != endIt; )
	{
		// Is this the client that needs removing?
		if (client == *it)
		{
			// Erase client from vector and fd_set
			// Return true. Keep on going through vector in case  (somehow)
			// there are multiple instance of client in the vector (shouldn't be)
			m_clients.erase(it);
			FD_CLR(fd, &m_sockSet);
			ret = true;
		}
		else
		{
			it++;
		}

	}
	return ret;
}


bool NetworkManager::RemoveServer(IpServer* server)
{
	bool ret = false;


	// Loop through entire server vector until the correct server is
	// found. 
	ServerVec_t::iterator it = m_servers.begin();
	ServerVec_t::iterator endIt = m_servers.end();
	int32_t fd = server->getSocketDesciptor();
	for (; it != endIt; )
	{
		// Is this the server that needs removing?
		if (server == *it)
		{
			// Erase server from vector and fd_set
			// Return true. Keep on going through vector in case  (somehow)
			// there are multiple instance of server in the vector (shouldn't be)
			m_servers.erase(it);
			FD_CLR(fd, &m_sockSet);
			ret = true;
		}
		else
		{
			it++;
		}

	}
	return ret;
}



void NetworkManager::initNewSockets()
{
	
	while (m_newClients.size() != 0)
	{
		ClientVec_t::iterator it = m_newClients.begin();
		IpClient* client = *it;
		m_clients.push_back(client);
		m_newClients.erase(it);

		// Start client connection.
		// Note that this will close and restart the connection
		// if it is already connected on a socket.
		client->startClient();

		// Check if socket descriptor is valid
		if (client->getSocketDesciptor() > 0)
		{
			// Add to FD_SET
			FD_SET(client->getSocketDesciptor(), &m_sockSet);
			//FD_CLR(client->getSocketDesciptor(), &m_sockSet);
		}
	}




	

	while (m_newServers.size() != 0)
	{
		ServerVec_t::iterator servIt = m_newServers.begin();

		IpServer* server = *servIt;

		m_servers.push_back(server);

		m_newServers.erase(servIt);
		// Start server listening
		// Note that this will close and restart the connection
		// if it is already connected on a socket.
		server->startServer();

		// Check if socket descriptor is valid
		if (server->getSocketDesciptor() > 0)
		{
			// Add to FD_SET
			FD_SET(server->getSocketDesciptor(), &m_sockSet);
			//FD_CLR(server->getSocketDesciptor(), &m_sockSet);
		}

		// Loop through map of all connected clients (unlikely any at this point)
		// Add to FD_SET if any valid found
		IpServer::SockAddrVec_t::iterator it2 = server->m_clientAddrVec.begin();
		IpServer::SockAddrVec_t::iterator endIt2 = server->m_clientAddrVec.end();
		for (; it2 != endIt2; it2++)
		{
			// Check if socket descriptor is valid
			if ((*it2).sd > 0)
			{
				// Add to FD_SET
				FD_SET((*it2).sd, &m_sockSet);
				//FD_CLR((*it).sd, &m_sockSet);
			}
		}
	}

}

void NetworkManager::serviceClient(IpClient* client)
{
	if (nullptr == client)
	{
		// TODO route error notification

	}
	else
	{
		IpClient::ClientStatus_t stat = client->getStatus();
		switch (stat)
		{
		case IpClient::ClientStatus_t::UNKNOWN:
		case IpClient::ClientStatus_t::NOT_CONNECTED:
			client->startClient();
			break;
		case IpClient::ClientStatus_t::CONNECTING:
			//client->startClient();
			break;
		case IpClient::ClientStatus_t::CONNECTED:
			if (client->onReceive())
			{
				// Something bad happened
				// TODO Attempt to reinit the connection
			}
			break;
		default:
			break;

		}

	}
}

void NetworkManager::serviceServer(IpServer* server, int32_t sd, IpServer::Connection_t& conn)
{
	if (nullptr == server)
	{
		// TODO route error notification

	}
	else
	{
		IpServer::ServerStatus_t stat = server->getStatus();

		if (server->getSocketDesciptor() == sd)
		{
			switch (stat)
			{
			case IpServer::ServerStatus_t::UNKNOWN:
			case IpServer::ServerStatus_t::NOT_CONNECTED:
				break;
			case IpServer::ServerStatus_t::LISTENING:

			case IpServer::ServerStatus_t::CONNECTED:
				// need to service server for each socket on it
				if (server->acceptSocket(sd, conn))
				{
					FD_SET(conn.sd, &m_sockSet);
				}

				break;
			default:
				break;

			}
		}
		else
		{
			// This socket is for the connection, not for accepting new sockets
			// Attempt to receive data on this socket
			if (server->onReceive(conn))
			{
				// TODO error handling

			}


		}
	}
}

uint32_t NetworkManager::connectionMaintenance(Message& tmr)
{



	// Service of a client consists of checking the health of sockets in CONNECTED
	// state and attempting to reinit connection of those in NOT_CONNECTED state

	// Loop through all clients and service each one individually
	ClientVec_t::iterator clientIt = m_clients.begin();
	const ClientVec_t::iterator clientEndIt = m_clients.end();
	while (clientEndIt != clientIt)
	{
		checkClientHealth(*clientIt);
		clientIt++;
	}

	// Service of a server consists of checking the health of sockets in CONNECTED
	// state and attempting to reinit connection of those in NOT_CONNECTED state

	// Loop through all servers and service each one individually
	ServerVec_t::iterator serverIt = m_servers.begin();
	ServerVec_t::iterator serverEndIt = m_servers.end();
	while (serverEndIt != serverIt)
	{
		IpServer* server = *serverIt;
		//serviceServer(server, server->getSocketDesciptor(), server->DEFAULT_CONNECTION);
		checkServerHealth(server);

		// Clean up dead connections for server
		IpServer::SockAddrVec_t::iterator connIt = (*serverIt)->m_clientAddrVec.begin();
		IpServer::SockAddrVec_t::iterator connEndIt = (*serverIt)->m_clientAddrVec.end();
		while (connEndIt != connIt)
		{
			// If the connection is dead, then remove it from the connection vector
			if ((*connIt).sd < 0)
			{
				(*serverIt)->m_clientAddrVec.erase(connIt);
			}
			else
			{

				connIt++;
			}

		}
		serverIt++;


	}
	return 0;
}



