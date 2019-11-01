#include "IpCore.h"
#include "IpUtils.h"
#ifdef OS_WINDOWS
#elif defined OS_LINUX
#include "errno.h"
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
		closeSocket(m_sd);
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
	if (GetLastError() == WSAEWOULDBLOCK || GetLastError() == WSAEALREADY)
	{
		err = 0;
	}
#elif defined OS_LINUX
	connect(sd, &m_sockaddr, sizeof(m_sockaddr));
	err = errno;
#elif defined OS_RTOS

#endif


	if (err < 0)
	{
		// Could not connect
		ret = false;
		// Log error code
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


	if (err < 0)
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
	err = bind(sd, (SOCKADDR*)& m_sockaddr, sizeof(m_sockaddr));

#elif defined OS_RTOS

#endif


	if (err < 0)
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


int32_t IpCore::acceptSocket(int32_t sd, sockaddr* const &addr, int32_t * const &addrlen)
{
	int32_t err = -1;
	int32_t newSd = -1;
#ifdef OS_WINDOWS
	newSd = accept(sd, addr, addrlen);
	if (newSd > 0)
	{
		err = 0;
	}
#elif defined OS_LINUX
	newSd = accept(sd, addr, addrlen);
	if (newSd > 0)
	{
		err = 0;
	}
#elif defined OS_RTOS

#endif


	if (err < 0)
	{
		// Could not connect

	}


	return newSd;
}

void IpCore::setHeartBeatMsg(std::string& msg)
{
	m_heartbeatMsg = msg;
}

std::string IpCore::getHeartBeatMsg()
{
	return m_heartbeatMsg;
}

bool IpCore::closeSocket(int32_t sd)
{
	bool ret = false;
	int32_t err = -1;
#ifdef OS_WINDOWS
	err = closesocket(sd);
#elif defined OS_LINUX
	close(sd);
	err = errno;
	// TODO fix errno handling
#elif defined OS_RTOS

#endif


	if (err < 0)
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

int32_t IpCore::sendData(const std::string& data, int32_t sd)
{
	if (0 == sd)
	{
		sd = m_sd;
	}
	
	int32_t ret = ::send(sd, data.c_str(), data.length(), 0);

	 
	return ret;
}


int32_t IpCore::recvData(std::vector<uint8_t>& data, uint16_t index, int32_t sd, uint16_t chunkSize)
{
	int32_t ret = 0;
	if (0 == sd)
	{
		sd = m_sd;
	}
	if (data.size() < (index + chunkSize))
	{
		data.resize(index + chunkSize);
	}
	ret = ::recv(sd, reinterpret_cast<char*>(&data[index]), chunkSize, 0);

	return ret;
}

bool IpCore::configureSocket(int32_t sd)
{
	bool ret = setNonBlockingSocket(sd);

	// TODO add more error handling...

	return ret;
}