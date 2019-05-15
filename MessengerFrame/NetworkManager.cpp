#include "NetworkManager.h"
#include <typeinfo>

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
	m_sockSet()
{
	FD_ZERO(&m_sockSet);
}


NetworkManager::~NetworkManager()
{
}

void NetworkManager::Initialize()
{


}

bool NetworkManager::Run()
{
	bool ret = false;
	//TODO
	while (1)
	{
		timeval timeOut;
		timeOut.tv_sec = 0;
		timeOut.tv_usec = 10000;

		fd_set readFd(m_sockSet);
		int32_t numSelected = select(FD_SETSIZE, &readFd, nullptr, nullptr, &timeOut);

		if (numSelected < 0)
		{
			// An error has occurred :(

		}
		else if (0 == numSelected)
		{
			// Continue to loop...just timed out
		}
		else
		{
			// A socket can be read on.


		}
		CheckSocketHealth();
	}
	return ret;
}


void NetworkManager::Terminate()
{
	ClientVec_t::iterator it = m_clients.begin();
	ClientVec_t::iterator endIt = m_clients.end();

	for (; it != endIt; it++)
	{
		(*it)->close((*it)->m_sd);
		(*it)->onDisconnect();
	}

	ServerVec_t::iterator it2 = m_servers.begin();
	ServerVec_t::iterator endIt2 = m_servers.end();

	for (; it2 != endIt2; it2++)
	{
		(*it2)->close((*it2)->m_sd);
		(*it2)->onDisconnect();

	}
}

bool NetworkManager::RegisterClient(IpClient* client)
{
	bool ret = true;
	if (nullptr != client)
	{
		// Add to list of client handles
		m_clients.push_back(client);

		// Start client connection.
		// Note that this will close and restart the connection
		// if it is already connected on a socket.
		ret = client->startClient();
		
		// Check if socket descriptor is valid
		if (client->m_sd > 0)
		{
			// Add to FD_SET
			FD_SET(client->m_sd, &m_sockSet);
		}
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
		m_servers.push_back(server);

		// Start server listening
		// Note that this will close and restart the connection
		// if it is already connected on a socket.
		ret = server->startServer();

		// Check if socket descriptor is valid
		if (server->m_sd > 0)
		{
			// Add to FD_SET
			FD_SET(server->m_sd, &m_sockSet);
		}

		// Loop through map of all connected clients (unlikely any at this point)
		// Add to FD_SET if any valid found
		IpServer::SockAddrMap_t::iterator it = server->m_clientAddrVec.begin();
		IpServer::SockAddrMap_t::iterator endIt = server->m_clientAddrVec.end();
		for (; it != endIt; it++)
		{
			// Check if socket descriptor is valid
			if ((*it).first > 0)
			{
				// Add to FD_SET
				FD_SET((*it).first, &m_sockSet);
			}
		}
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
	ClientVec_t::iterator it = m_clients.begin();
	ClientVec_t::iterator endIt = m_clients.end();

	for (; it != endIt; )
	{
		if (client == *it)
		{
			m_clients.erase(it);
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
	ServerVec_t::iterator it = m_servers.begin();
	ServerVec_t::iterator endIt = m_servers.end();

	for (; it != endIt; )
	{
		if (server == *it)
		{
			m_servers.erase(it);
			ret = true;
		}
		else
		{
			it++;
		}

	}
	return ret;
}

void NetworkManager::CheckSocketHealth()
{
	//TODO

}