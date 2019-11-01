#include "IpUtils.h"


#ifdef OS_LINUX
uint32_t sendSocket(const uint8_t* ptr, uint32_t len)
{
	uint32_t ret = 0;



	return ret;

}

uint32_t recvSocket(const uint8_t* buf)
{
	uint32_t ret = 0;



	return ret;

}

bool connectSocket(int32_t fd)
{
	bool ret = false;



	return ret;

}

bool listenSocket(int32_t fd)
{
	bool ret = false;



	return ret;

}

bool acceptSocket(int32_t fd)
{
	bool ret = false;



	return ret;

}

bool setNonBlockingSocket(int32_t fd)
{
	bool ret = false;



	return ret;

}



#endif


#ifdef OS_WINDOWS


bool connectSocket(int32_t fd)
{
	bool ret = false;



	return ret;

}

bool listenSocket(int32_t fd)
{
	bool ret = false;



	return ret;

}


bool setNonBlockingSocket(int32_t fd)
{
	int32_t err = 0;
	bool ret = false;
#ifdef OS_WINDOWS
	unsigned long mode = 1;
	err = (ioctlsocket(fd, FIONBIO, &mode));
#else
	int32_t flags = fcntl(fd, F_GETFL, 0);
	if (flags == -1) return false;
	flags = (flags | O_NONBLOCK);
	err = (fcntl(fd, F_SETFL, flags) == 0);
#endif
	if (0 == err)
	{
		ret = true;

	}
	else
	{
		// TODO route error logging
		ret = false;
	}

	return ret;

}


#endif