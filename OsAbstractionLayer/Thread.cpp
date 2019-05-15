#include "Thread.h"



Thread::Thread() : 
	m_heapSize(DEFAULT_HEAP_SIZE),
	m_priority(DEFAULT_PRIORITY),
	m_runPtr(nullptr),
	m_param(nullptr),
	m_threadId(INVALID_TID),
	m_threadHandlePtr(nullptr) 
{
}


Thread::~Thread()
{
}

Thread::Thread(uint32_t(Run)(void*), void* param, uint32_t heapSize, uint16_t priority) :
	m_heapSize(heapSize),
	m_priority(priority),
	m_runPtr(Run),
	m_param(param),
	m_threadId(INVALID_TID),
	m_threadHandlePtr(nullptr)
{


}

bool Thread::setFunction(uint32_t(*Run)(void*), void* param)
{
	bool ret = false;

	if (nullptr != Run)
	{
		ret = true;
	}
	m_runPtr = Run;
	m_param = param;
	return ret;
}


bool Thread::startThread()
{
	bool ret = false;
	if (nullptr != m_runPtr)
	{

		ThreadProc_t threadProc =
		{
			m_runPtr,
			m_param
		};
#ifdef OS_WINDOWS || defined OS_LINUX

		m_threadHandlePtr = new std::thread(m_runPtr, m_param);
		
	
		
#elif defined OS_RTOS

#endif

		
	}
	return ret;
}
bool Thread::stopThread()
{
	bool ret = false;

	return ret;
}



