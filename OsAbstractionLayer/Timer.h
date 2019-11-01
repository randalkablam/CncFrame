#pragma once
#include "OsEnv.h"

class Timer
{
public:
	Timer(bool isPeriodic, uint64_t period);
	~Timer();

	bool m_isPeriodic;
	uint64_t m_period;
	

private:
	bool m_isActive;
};

