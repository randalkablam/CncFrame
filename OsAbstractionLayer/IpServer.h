#pragma once
#include "IpCore.h"
#include <vector>
#include <map>
class IpServer :
	public IpCore
{
public:

	enum class ConnStatus_t
	{
		UNKNOWN,
		NOT_CONNECTED,
		CONNECTED,
		INVALID

	};

	typedef struct
	{
		int32_t sd = -1;
		sockaddr addr;
		ConnStatus_t stat = ConnStatus_t::UNKNOWN;
	} Connection_t;

	Connection_t DEFAULT_CONNECTION;


	IpServer(const std::string& ipAddr, uint16_t port);
	~IpServer();

	bool startServer();
	bool stopServer();

	bool acceptSocket(int32_t sd, Connection_t& conn);
	bool handleBrokenConn(int32_t sd);

	virtual bool onReceive(Connection_t& conn) = 0;
	virtual bool onConnect(Connection_t& conn) = 0;
	virtual bool onDisconnect(Connection_t& conn) = 0;




	typedef std::vector<Connection_t> SockAddrVec_t;
	SockAddrVec_t m_clientAddrVec;


	enum class ServerStatus_t
	{
		UNKNOWN,
		NOT_CONNECTED,
		LISTENING,
		CONNECTED, // TODO remove
		INVALID

	};
	ServerStatus_t m_serverStatus;

	inline void setStatus(ServerStatus_t stat)
	{
		if (stat < ServerStatus_t::INVALID)
		{
			m_serverStatus = stat;
		}
		else
		{
			m_serverStatus = ServerStatus_t::UNKNOWN;
		}
	}
	inline ServerStatus_t getStatus(void)
	{
		return m_serverStatus;
	}

	inline int32_t getSocketDesciptor() const
	{
		return m_sd;
	}

};

