#include "TimeUtils.h"
#ifdef OS_WINDOWS
#include <synchapi.h>
#elif defined OS_LINUX

#elif defined OS_RTOS

#endif


void OsSleep(uint32_t nanoseconds)
{
#ifdef OS_WINDOWS
	Sleep(nanoseconds / NANOSEC_IN_MILISEC);

#elif defined OS_LINUX

#elif defined OS_RTOS


#endif

}