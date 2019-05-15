#pragma once
#include "OsEnv.h"
#ifdef OS_LINUX




#endif


#ifdef OS_WINDOWS



#endif

uint32_t sendSocket(const uint8_t* ptr, uint32_t len);

uint32_t recvSocket(const uint8_t* buf);

bool connectSocket(int32_t fd);

bool listenSocket(int32_t fd);

bool acceptSocket(int32_t fd);

bool setNonBlockingSocket(int32_t fd);

// TODO determine what other common operations need to be added