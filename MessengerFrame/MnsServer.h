#pragma once
#include <IpServer.h>
#include "SysEnv.h"
class MnsServer : public IpServer
{
public:
	// One name server per application...
	static MnsServer* getMnsServer(void);

private:
	MnsServer();
	~MnsServer();

	static MnsServer* ms_mnsServerPtr;


	bool onReceive(Connection_t& conn);
	bool onConnect(Connection_t& conn);
	bool onDisconnect(Connection_t& conn);

};

