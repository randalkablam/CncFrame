#include "TimerManager.h"
#ifdef OS_WINDOWS
#include <iostream>
#include <chrono>

#elif defined OS_LINUX
#include <signal.h>
#include <time.h>
#elif defined OS_RTOS

#endif

TimerManager* TimerManager::ms_timerManager = nullptr;


void TimerManager::Start()
{
}

bool TimerManager::Run()
{

	//TODO clean up
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	tick();
	handleTimerTick();
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> timeSpan = t2 - t1;

	//std::cout <<  timeSpan.count() << std::endl;
	return true;
}

void TimerManager::Stop()
{
}

TimerManager::TimerManager() :
	Manager(typeid(TimerManager).name()),
	m_sysTick(0),
	m_timerMap()
{
}


TimerManager::~TimerManager()
{
	//TODO clean up all timers/messages in maps
}


void TimerManager::Add(TimerMsg* timerMsg, Location* loc)
{
	if (nullptr == timerMsg || nullptr == loc)
	{
		// Route error alert
	}
	else
	{

		std::pair<TimerMsg*, Location*> newTimer = std::pair<TimerMsg*, Location*>(timerMsg, loc);
		uint64_t timeoutTime = m_sysTick + timerMsg->getTimer()->m_period;
		TimerMap_t::iterator mapIt = m_timerMap.find(timeoutTime);
		if (mapIt != m_timerMap.end())
		{
			// There already exist timers for this timeout time
			// Simple add to the timeout vector
			(*mapIt).second.push_back(newTimer);
		}
		else
		{
			// No timers exist for this timeout time yet.
			// Add an entirely new timeout vector
			TimerVec_t newVec;
			newVec.push_back(newTimer);
			m_timerMap.insert({ timeoutTime, newVec });
		}
	}
}


void TimerManager::handleTimerTick()
{
	TimerMap_t::iterator it = m_timerMap.find(m_sysTick);
	
	// Should have already confirmed that it is in map.
	// Double checking
	if (m_timerMap.end() != it)
	{
		TimerVec_t::iterator timerIt = it->second.begin();
		
		for (; timerIt != it->second.end(); timerIt++)
		{
			TimerMsg* timerMsg = (*timerIt).first;
			if (nullptr != timerMsg)
			{
				Timer* timer = timerMsg->getTimer();
				Location* loc = (*timerIt).second;
				if (nullptr != timer)
				{
					// Check whether timer needs to be restarted
					// or flat out deleted
					if (timer->m_isPeriodic)
					{
						Add(timerMsg, loc);

					}
					else
					{
						delete timer;
						timerMsg->setTimer(nullptr);
					}

					// Send message to thread holding timer
					// TODO
					if (nullptr != loc)
					{
						loc->enqueueItem(timerMsg);

					}


				}
			}
		}

		m_timerMap.erase(m_sysTick);
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
	std::this_thread::sleep_for(std::chrono::milliseconds(interval));
	//Sleep(interval);
#elif defined OS_LINUX
	nanosleep(interval * 1000 * 1000);
#elif defined OS_RTOS

#endif
}