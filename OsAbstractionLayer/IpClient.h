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
	

	enum class ClientStatus_t
	{
		UNKNOWN,
		NOT_CONNECTED,
		CONNECTING,
		CONNECTED,
		INVALID

	};
	ClientStatus_t m_clientStatus;

	inline void setStatus(ClientStatus_t stat)
	{
		if (stat < ClientStatus_t::INVALID)
		{
			m_clientStatus = stat;
		}
		else
		{
			m_clientStatus = ClientStatus_t::UNKNOWN;
		}
	}
	inline ClientStatus_t getStatus(void)
	{
		return m_clientStatus;
	}


	inline int32_t getSocketDesciptor() const
	{
		return m_sd;
	}
};

