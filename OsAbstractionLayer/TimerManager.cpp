#include "TimerManager.h"
#ifdef OS_WINDOWS

#elif defined OS_LINUX
#include <signal.h>
#include <time.h>
#elif defined OS_RTOS

#endif


TimerManager::TimerManager() :
	m_sysTick(0),
	m_timerMap()
{
}


TimerManager::~TimerManager()
{
}


void TimerManager::Add(Timer* timer)
{

}


void TimerManager::handleTimerTick()
{
	TimerMap_t::iterator it = m_timerMap.find(m_sysTick);
	
	// Should have already confirmed that it is in map.
	// Double checking
	if (m_timerMap.end() != it)
	{
		TimerVec_t::iterator timerIt = it->second.begin();
		m_timerMap.erase(m_sysTick);
		for (; timerIt != it->second.end(); timerIt++)
		{
			Timer* timer = *timerIt;
			if (nullptr != timer)
			{

				// Send message to thread holding timer
				// TODO

				// Check whether timer needs to be restarted
				// or flat out deleted
				if (timer->m_isPeriodic)
				{
					Add(timer);

				}
				else
				{
					delete timer;
				}
			}
		}

	}


}

void TimerManager::tick()
{

	SleepMilli(SYS_TICK_INTERVAL);
	m_sysTick += SYS_TICK_INTERVAL;
	if (checkTimerMap())
	{
		handleTimerTick();
	}

}

void TimerManager::SleepMilli(uint32_t interval)
{
#ifdef OS_WINDOWS
	Sleep(interval);
#elif defined OS_LINUX
	nanosleep(interval);
#elif defined OS_RTOS

#endif
}