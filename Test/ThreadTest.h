#pragma once
#include "ThreadManager.h"
#include "TimeUtils.h"
class ThreadTest
{
public:
	ThreadTest();
	~ThreadTest();
	

	bool runTest();

};
static uint32_t ProcFunction(void* param);
