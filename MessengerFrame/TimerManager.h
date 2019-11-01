#pragma once
#include "Timer.h"
#include "TimerMsg.h"
#include <map>
#include <vector>
#include "Location.h"
#include "Manager.h"

class TimerManager : Manager
{
public:
	static void SleepMilli(uint32_t interval);
	void Add(TimerMsg* timerMsg, Location* loc);
	static inline TimerManager* getTimerManager()
	{
		if (nullptr == ms_timerManager)
		{
			ms_timerManager = new TimerManager();
		}
		// no else clause required ms_timerManager already constructed

		return ms_timerManager;
	}
protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();
private:
	TimerManager();
	~TimerManager();

	static TimerManager* ms_timerManager;
	// Operating under assumption that we are not going to 
	// have many timers operating at once. std::map uses RB tree
	// which has log(n) lookup/insertion times.
	// Cleaner to implement and possibly not worse than a hash table
	typedef std::vector<std::pair<TimerMsg*, Location*>> TimerVec_t;
	typedef std::map<uint64_t, TimerVec_t> TimerMap_t;
	
	// Maps time the timer goes off to the actual timer
	// When the systick count maps to a timer, then we have a match.
	TimerMap_t m_timerMap;

	uint64_t m_sysTick;

	inline bool checkTimerMap(void)
	{
		bool ret = false;
		if (m_timerMap.end() == m_timerMap.find(m_sysTick))
		{
			ret = true;
		}
		return false;
	}

	void handleTimerTick(void);

	void tick(void);

};


