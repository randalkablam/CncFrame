#pragma once
#include "OsEnv.h"
class Priority
{
public:
	Priority();
	~Priority();

	void setPriority(uint32_t priority);
	uint32_t getPriority();

private:
	uint32_t m_priorityNum;

};

