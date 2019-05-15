#include "ThreadTest.h"

#include <iostream>

ThreadTest::ThreadTest()
{
}


ThreadTest::~ThreadTest()
{
}


bool ThreadTest::runTest()
{
	bool ret = false;

	
	ThreadManager* threadMan = ThreadManager::getThreadManager();

	threadMan->createThread(ProcFunction, nullptr);
	threadMan->createThread(ProcFunction, nullptr);
	threadMan->createThread(ProcFunction, nullptr);
	threadMan->createThread(ProcFunction, nullptr);
	threadMan->waitOnThreads();
	return ret;

}

uint32_t ProcFunction(void* param)
{
	uint32_t count = 0;
	while (1)
	{

		std::cout << "Count " << count << std::endl;
		

		OsSleep(10000000); // 10 msec

		count++;

	}

}