#include "ThreadManager.h"


ThreadManager* ThreadManager::m_threadManager = nullptr;

ThreadManager* ThreadManager::getThreadManager()
{
	if (nullptr == m_threadManager)
	{
		m_threadManager = new ThreadManager();

	}
	return m_threadManager;
}

ThreadManager::ThreadManager() :
	m_nextThreadId(0)
{
}


ThreadManager::~ThreadManager()
{
}

uint32_t ThreadManager::createThread(uint32_t(*Run)(void*), void* param)
{
	uint32_t ret = INVALID_TID;
	// Creates and starts thread for given function
	Thread* t = new Thread(Run, param);

	m_threadMap[m_nextThreadId] = t;

	t->startThread();

	bool threadOk = checkThread(m_nextThreadId);

	if (threadOk)
	{
		ret = m_nextThreadId;
	}


	m_nextThreadId++;

	return ret;

}


bool ThreadManager::killThread(uint32_t threadId)
{
	bool ret = false;

	return ret;
}



bool ThreadManager::checkThread(uint32_t threadId)
{

	bool ret = false;

	ThreadMap_t::iterator it(m_threadMap.find(threadId));
	ThreadMap_t::iterator endIt(m_threadMap.end());


	if (it != endIt)
	{
		// The thread number is at least still registered to the map.



		// TODO add some health checking steps if possible

		ret = true;


	}

	return ret;

}


bool ThreadManager::waitOnThreads()
{
	bool ret = false;

#ifdef OS_WINDOWS || defined OS_LINUX

	ThreadMap_t::iterator it(m_threadMap.begin());
	ThreadMap_t::iterator endIt(m_threadMap.end());

	uint32_t i = 0;
	while (it != endIt)
	{
		std::thread* threadHandlePtr = it->second->m_threadHandlePtr;
		
		threadHandlePtr->join();
		it++;
		i++;
	}

#elif defined OS_RTOS


#endif


	return ret;

}