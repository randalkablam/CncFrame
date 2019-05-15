#pragma once
#include "OsEnv.h"

class Timer
{
public:
	Timer();
	~Timer();

	bool m_isPeriodic;
	uint64_t m_period;

};

