#pragma once
#include "IpCore.h"
class IpClient : public IpCore
{
public:
	IpClient(const std::string &ipAddr, uint16_t port);
	~IpClient();

	bool startClient();
	bool stopClient();

	virtual bool onReceive() = 0;
	virtual bool onConnect() = 0;
	virtual bool onDisconnect() = 0;
	
	
};

