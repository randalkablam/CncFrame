#pragma once
#include "Manager.h"
#include <IpClient.h>
#include <IpServer.h>
#include <vector>
#include "TimerMsg.h"

typedef TimerMsg SocketMgmtTimer_t;

class NetworkManager : public Manager
{
public:
	static NetworkManager* getNetworkManager();
	
	bool RegisterClient(IpClient* client);
	bool RegisterServer(IpServer* server);
	bool RemoveClient(IpClient* client);
	bool RemoveServer(IpServer* server);
	uint32_t connectionMaintenance(Message& tmr);

protected:

	static NetworkManager* m_networkManagerPtr;

	NetworkManager();
	~NetworkManager();

	typedef std::vector<IpClient*> ClientVec_t;
	typedef std::vector<IpServer*> ServerVec_t;

 
	void Start();
	bool Run();
	void Stop();
	
	void checkClientHealth(IpClient* client);
	void checkServerHealth(IpServer* server);

	ClientVec_t m_clients;
	ServerVec_t m_servers;

	ClientVec_t m_newClients;
	ServerVec_t m_newServers;
	void initNewSockets();


	fd_set m_sockSet;
private:
	void serviceClient(IpClient* client);
	void serviceServer(IpServer* server, int32_t sd, IpServer::Connection_t& conn);

	
	const uint64_t SOCKET_SERVICE_PERIOD = 500; // 500ms

};

