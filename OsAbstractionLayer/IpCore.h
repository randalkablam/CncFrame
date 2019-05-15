#pragma once
#include "OsEnv.h"
#include <string>
#ifdef OS_WINDOWS
//#include <WinSock2.h>
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

	int32_t createSocket();

	bool connectTo(int32_t sd);
	bool listenOn(int32_t sd);
	bool bindSocket(int32_t sd);
	bool accecptSocket(int32_t sd, sockaddr*& addr, int32_t*& addrlen);
	bool close(int32_t sd);

	int32_t send(const std::string &data);
	int32_t recv(const std::string& data);

	uint16_t m_port;
	std::string m_ipAddr;
	struct sockaddr_in m_sockaddr;
	int32_t m_sd;
};

