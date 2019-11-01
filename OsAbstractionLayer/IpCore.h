#pragma once
#include "OsEnv.h"
#include <string>
#include <vector>
#ifdef OS_WINDOWS
#pragma comment(lib, "Ws2_32.lib")

#elif defined OS_LINUX
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#elif defined OS_RTOS


#endif

class IpCore
{
public:



	IpCore(uint16_t port, const std::string& ipAddr);
	~IpCore();
	virtual int32_t sendData(const std::string& data, int32_t sd = 0);
	virtual int32_t recvData(std::vector<uint8_t>& data, uint16_t index, int32_t sd = 0, uint16_t chunkSize = DEFAULT_CHUNK_SIZE);
	bool closeSocket(int32_t sd);
	virtual std::string getHeartBeatMsg();

protected:

	int32_t createSocket();

	bool connectTo(int32_t sd);
	bool listenOn(int32_t sd);
	bool bindSocket(int32_t sd);
	int32_t acceptSocket(int32_t sd, sockaddr* const &addr, int32_t* const &addrlen);
	
	bool configureSocket(int32_t sd);

	virtual void setHeartBeatMsg(std::string& msg);
	std::string m_heartbeatMsg;

	uint16_t m_port;
	std::string m_ipAddr;
	struct sockaddr_in m_sockaddr;
	int32_t m_sd;

	static const uint16_t DEFAULT_CHUNK_SIZE = 50;

};

