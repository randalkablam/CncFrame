#pragma once
#include "OsEnv.h"

#ifdef OS_WINDOWS

#define DEFAULT_HEAP_SIZE 1024
#define DEFAULT_PRIORITY 0

#elif defined OS_LINUX

#define DEFAULT_HEAP_SIZE 1024
#define DEFAULT_PRIORITY 0
#else
#define DEFAULT_HEAP_SIZE 1024
#define DEFAULT_PRIORITY 0
#endif
#include <thread>
#define INVALID_TID 0xFFFFFFFF

class Thread
{
public:
	Thread();
	Thread(uint32_t(Run)(void*), void* param, uint32_t heapSize = DEFAULT_HEAP_SIZE, uint16_t priority = DEFAULT_PRIORITY);
	~Thread();
	bool setFunction(uint32_t(*Run)(void*), void* param);

	uint32_t m_threadId;

#ifndef OS_RTOS 
	std::thread* m_threadHandlePtr;
#endif

	typedef struct
	{
		uint32_t(*runPtr)(void*);
		void* param;
	} ThreadProc_t;

	bool startThread();
	bool stopThread();

private:
	uint32_t(*m_runPtr)(void*);
	void* m_param;


	uint32_t m_heapSize;
	uint32_t m_priority;


	


	

};

