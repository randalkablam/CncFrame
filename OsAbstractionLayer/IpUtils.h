#pragma once
#include "OsEnv.h"
#ifdef OS_LINUX




#endif


#ifdef OS_WINDOWS



#endif

bool connectSocket(int32_t fd);

bool listenSocket(int32_t fd);

bool setNonBlockingSocket(int32_t fd);

// TODO determine what other common operations need to be added