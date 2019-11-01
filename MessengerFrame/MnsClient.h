#pragma once
#include <IpClient.h>
class MnsClient : public IpClient
{
public:
	// One name server per application...
	static MnsClient* getMnsClient(void);

private:
	MnsClient();
	~MnsClient();

	static MnsClient* ms_mnsClientPtr;


	bool onReceive();
	bool onConnect();
	bool onDisconnect();


};

