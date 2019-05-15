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