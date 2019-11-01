#include "IpServer.h"

#include <iostream>

IpServer::IpServer(const std::string& ipAddr, uint16_t port) :
	IpCore(port, ipAddr),
	m_clientAddrVec(),
	m_serverStatus(ServerStatus_t::NOT_CONNECTED)
{
}


IpServer::~IpServer()
{
	bool serverStopped = stopServer();
	if (!serverStopped)
	{
		//TODO additional error handling/logging
	}
}


bool IpServer::startServer()
{
	bool ret = false;

	// TODO
	int32_t sd = createSocket();
	if (sd > 0)
	{
		// Socket created is valid
		bool bindOk = bindSocket(sd);
		// TODO additional error handling code if bind/listen failed
		if (!bindOk)
		{
			setStatus(ServerStatus_t::NOT_CONNECTED);
		}
		else
		{
			// Attempt to listen on binded socket
			bool listenOk = listenOn(sd);
			if (!listenOk)
			{
				setStatus(ServerStatus_t::NOT_CONNECTED);
			}
			else
			{
				setStatus(ServerStatus_t::LISTENING);
			}
			
		}
	}
	else
	{
		// TODO get error
		std::cout << GetLastError() << std::endl;

	}
	return ret;

}


bool IpServer::stopServer()
{
	bool ret = false;

	// Note that IpCore will close m_sd but we stil need
	// to close all the client sockets...
	SockAddrVec_t::iterator it = m_clientAddrVec.begin();
	SockAddrVec_t::iterator endIt = m_clientAddrVec.end();
	for (; it != endIt; it++)
	{

		closeSocket((*it).sd);

	}
	
	return ret;

}

bool IpServer::acceptSocket(int32_t sd, Connection_t& conn)
{
	bool ret = false;
	int32_t newSd = -1;
	int32_t addrlen = sizeof(sockaddr);

	newSd = IpCore::acceptSocket(sd, &conn.addr, &addrlen);
	if (newSd > 0)
	{
		
		// Add client to connection vector
		conn.stat = ConnStatus_t::CONNECTED;
		conn.sd = newSd;

		m_clientAddrVec.push_back(conn);
		ret = onConnect(conn);
		//todo error handling for on connect...
		

	}

	return ret;
}

bool IpServer::handleBrokenConn(int32_t sd)
{
	//  right now we just want to immediately close broken connections
	// it is the client's responsibility to reconnect if it needs to.
	
	closeSocket(sd);
	SockAddrVec_t::iterator it = m_clientAddrVec.begin();
	SockAddrVec_t::iterator endIt = m_clientAddrVec.end();
	for (; it != endIt; )
	{
		int32_t tempSd = (*it).sd;
		if (sd == tempSd)
		{
			(*it).sd = -1;
		}
		else
		{
			it++;
		}

	}

	return true;
}

