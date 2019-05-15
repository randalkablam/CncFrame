#pragma once
#include "Manager.h"
#include <IpClient.h>
#include <IpServer.h>
#include <vector>
class NetworkManager : public Manager
{
public:
	static NetworkManager* getNetworkManager();
	
	bool RegisterClient(IpClient* client);
	bool RegisterServer(IpServer* server);
	bool RemoveClient(IpClient* client);
	bool RemoveServer(IpServer* server);

protected:

	static NetworkManager* m_networkManagerPtr;

	NetworkManager();
	~NetworkManager();

	typedef std::vector<IpClient*> ClientVec_t;
	typedef std::vector<IpServer*> ServerVec_t;

 
	void Initialize();
	bool Run();
	void Terminate();
	
	void CheckSocketHealth();

	ClientVec_t m_clients;
	ServerVec_t m_servers;

	fd_set m_sockSet;
};

