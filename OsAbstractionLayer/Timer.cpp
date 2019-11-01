#include "Timer.h"
#include "OsEnv.h"
#ifdef OS_LINUX
#include <sys/time.h>
#endif


Timer::Timer(bool isPeriodic, uint64_t period) :
	m_isPeriodic(isPeriodic),
	m_period(period),
	m_isActive(false)
{
}


Timer::~Timer()
{
}

