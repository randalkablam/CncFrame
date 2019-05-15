#pragma once
#include "OsEnv.h"
#include "Thread.h"
#include <vector>
#include <map>

class ThreadManager
{
public:
	static const uint32_t MAX_THREADS = 128;


	static ThreadManager* getThreadManager();
	

	uint32_t createThread(uint32_t(*Run)(void*), void* param);
	bool killThread(uint32_t threadId);
	
	bool waitOnThreads();
	

private:

	ThreadManager();
	~ThreadManager();

	static ThreadManager* m_threadManager;

	typedef std::map<uint32_t, Thread*> ThreadMap_t;

	ThreadMap_t m_threadMap;
	
	bool checkThread(uint32_t threadId);

	// Denotes next thread id, thread id's are never reused.
	uint32_t m_nextThreadId;



};

