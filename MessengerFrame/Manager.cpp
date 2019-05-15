#include "Manager.h"
#include "ThreadManager.h"


Manager::Manager(std::string managerName) :
	m_managerName(managerName),
	m_msgReaderStarted(false),
	m_runStarted(false),
	tidRun(INVALID_TID),
	tidMsg(INVALID_TID)
{
	ThreadManager* tm = ThreadManager::getThreadManager();
	tidRun = tm->createThread(ThreadRun, this);
	tidMsg = tm->createThread(ThreadMsg, this);
}


Manager::~Manager()
{
	ThreadManager* tm = ThreadManager::getThreadManager();
	if (INVALID_TID != tidRun)
	{
		tm->killThread(tidRun);
	}
	if (INVALID_TID != tidMsg)
	{
		tm->killThread(tidMsg);
	}
}

std::string Manager::getName()
{
	return m_managerName;
}

void Manager::StartRun()
{
	if (!m_runStarted)
	{
		m_runStarted = true;
		Initialize();
		while (1)
		{
			// Loop and receive msgs/data from queue
			bool terminate = Run();
			if (terminate)
			{
				Terminate();

			}
		}
	}
}
void Manager::StartMsgReader()
{
	if (!m_msgReaderStarted)
	{
		m_msgReaderStarted = true;
		while (1)
		{
			// Loop and receive msgs/data from queue
			bool terminate = ReceiveMsgs();
			if (terminate)
			{
				Terminate();

			}
		}
	}
}

bool Manager::ReceiveMsgs()
{
	// Returning true will terminate the manager.
	// It is indicative of an error in processing
	bool ret = false;

	return ret;
}


static uint32_t ThreadRun(void* ptr)
{
	Manager* mgr = static_cast<Manager*>(ptr);
	
	mgr->StartRun();

	return 0;
}
static uint32_t ThreadMsg(void* ptr)
{

	Manager* mgr = static_cast<Manager*>(ptr);
	
	mgr->StartMsgReader();

	return 0;
}