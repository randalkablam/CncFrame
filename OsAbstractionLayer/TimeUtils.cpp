#include "TimeUtils.h"
#ifdef OS_WINDOWS
#include <synchapi.h>
#elif defined OS_LINUX
#include <time.h>
#elif defined OS_RTOS

#endif


void OsSleep(uint32_t nanoseconds)
{
#ifdef OS_WINDOWS
	Sleep(nanoseconds / NANOSEC_IN_MILISEC);

#elif defined OS_LINUX
	nanosleep(nanoseconds);
#elif defined OS_RTOS


#endif

}

uint64_t getSysTime()
{
#ifdef OS_WINDOWS
	uint64_t ret = GetTickCount64();
#else
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	uint64_t ret =
		(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
#endif
	return ret;
}