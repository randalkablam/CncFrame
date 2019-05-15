#pragma once
#include "IpCore.h"
#include <vector>
#include <map>
class IpServer :
	public IpCore
{
public:
	IpServer(const std::string& ipAddr, uint16_t port);
	~IpServer();

	bool startServer();
	bool stopServer();

	virtual bool onReceive() = 0;
	virtual bool onConnect() = 0;
	virtual bool onDisconnect() = 0;


	typedef std::map<int32_t, sockaddr> SockAddrMap_t;
	SockAddrMap_t m_clientAddrVec;


};

