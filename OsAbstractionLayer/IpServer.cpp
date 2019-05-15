#include "IpServer.h"



IpServer::IpServer(const std::string& ipAddr, uint16_t port) :
	IpCore(port, ipAddr),
	m_clientAddrVec()
{
}


IpServer::~IpServer()
{
	// Note that IpCore will close m_sd but we stil need
	// to close all the client sockets...
	SockAddrMap_t::iterator it = m_clientAddrVec.begin();
	SockAddrMap_t::iterator endIt = m_clientAddrVec.end();
	for (; it != endIt; it++)
	{
		
		close((*it).first);

	}
}


bool IpServer::startServer()
{
	bool ret = false;

	// TODO

	return ret;

}


bool IpServer::stopServer()
{
	bool ret = false;

	// TODO

	return ret;

}