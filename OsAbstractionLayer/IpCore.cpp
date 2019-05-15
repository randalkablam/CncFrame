#include "IpCore.h"
//#include <WinSock2.h>
#ifdef OS_WINDOWS
#elif defined OS_LINUX

#elif defined OS_RTOS

#endif


IpCore::IpCore(uint16_t port, const std::string& ipAddr) :
	m_port(port),
	m_ipAddr(ipAddr),
	m_sockaddr(),
	m_sd(-1)
{
	
	m_sockaddr.sin_family = AF_INET;
	m_sockaddr.sin_addr.s_addr = inet_addr(ipAddr.c_str());
	m_sockaddr.sin_port = htons(port);
}


IpCore::~IpCore()
{
	if (-1 != m_sd)
	{
		close(m_sd);
	}
}

int32_t IpCore::createSocket()
{
	m_sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	return m_sd;
}


bool IpCore::connectTo(int32_t sd)
{
	bool ret = false;
	int32_t err = -1;
#ifdef OS_WINDOWS
	err = connect(sd, (SOCKADDR*)&m_sockaddr, sizeof(m_sockaddr));
#elif defined OS_LINUX

#elif defined OS_RTOS

#endif


	if (ret < 0)
	{
		// Could not connect
		ret = false;

	}
	else
	{
		ret = true;
	}


	return ret;
}


bool IpCore::listenOn(int32_t sd)
{
	bool ret = false;
	int32_t err = -1;
#ifdef OS_WINDOWS
	err = listen(sd, SOMAXCONN);
#elif defined OS_LINUX

#elif defined OS_RTOS

#endif


	if (ret < 0)
	{
		// Could not connect
		ret = false;

	}
	else
	{
		ret = true;
	}


	return ret;
}

bool IpCore::bindSocket(int32_t sd)
{
	bool ret = false;
	int32_t err = -1;
#ifdef OS_WINDOWS
	err = bind(sd, (SOCKADDR*) &m_sockaddr, sizeof(m_sockaddr));
#elif defined OS_LINUX

#elif defined OS_RTOS

#endif


	if (ret < 0)
	{
		// Could not connect
		ret = false;

	}
	else
	{
		ret = true;
	}


	return ret;
}


bool IpCore::accecptSocket(int32_t sd, sockaddr* &addr, int32_t *&addrlen)
{
	bool ret = false;
	int32_t err = -1;
#ifdef OS_WINDOWS
	err = accept(sd, addr, addrlen);
#elif defined OS_LINUX

#elif defined OS_RTOS

#endif


	if (ret < 0)
	{
		// Could not connect
		ret = false;

	}
	else
	{
		ret = true;
		m_sd = -1;
	}


	return ret;
}

bool IpCore::close(int32_t sd)
{
	bool ret = false;
	int32_t err = -1;
#ifdef OS_WINDOWS
	err = closesocket(sd);
#elif defined OS_LINUX

#elif defined OS_RTOS

#endif


	if (ret < 0)
	{
		// Could not connect
		ret = false;

	}
	else
	{
		ret = true;
		m_sd = -1;
	}


	return ret;
}

int32_t IpCore::send(const std::string& data)
{
	int32_t ret = 0;
	return ret;
}


int32_t IpCore::recv(const std::string& data)
{
	int32_t ret = 0;
	return ret;
}