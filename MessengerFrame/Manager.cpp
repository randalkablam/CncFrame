#include "Manager.h"
#include <ThreadManager.h>
#include "Slot.h"
#include "Boot/ManagerBooter.h"
#include "CmdMessage.h"
#include "NameServer.h"
#include "HeartbeatMsg.h"

Manager::Manager(const std::string& managerName) :
	m_managerName(managerName),
	m_msgReaderStarted(false),
	m_runStarted(false),
	tidRun(INVALID_TID),
	tidMsg(INVALID_TID),
	m_executionMutex(),
	m_condVar(),
	turnSemaphore(0),
	m_location(managerName),
	m_mailbox(),
	m_isStarted(false)
{
	ManagerBooter* mgrBooter = ManagerBooter::getManagerBooter();
	Slot* sl = new Slot(this);
	sl->registerSlot(std::bind(&Manager::recvCmd, this, std::placeholders::_1));
	CmdMessage msg;
	addSlot(*sl, msg);
	
	Slot* sl2 = new Slot(this);
	sl2->registerSlot(std::bind(&Manager::recvHeartbeat, this, std::placeholders::_1));
	HeartbeatMsg hbMsg;
	addSlot(*sl2, hbMsg);



	NameServer* ns = NameServer::getNameServer();
	ns->RegisterLocation(&m_location, &m_mailbox, managerName);
	
	



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

void Manager::StartManager()
{
	// Only start manager if it hasn't already been started.
	if (!m_isStarted)
	{
		ThreadManager* tm = ThreadManager::getThreadManager();
		tidRun = tm->createThread(ThreadRun, this);
		tidMsg = tm->createThread(ThreadMsg, this);
		m_isStarted = true;
	}
}

bool Manager::sendMsg(Message& msg, Location& loc)
{
	bool ret = false;
			
	msg.setSrc(m_location);
	msg.setDest(loc);

	ret = loc.enqueueItem(&msg);

	return ret;
}

uint32_t Manager::recvCmd(Message& msg)
{
	uint32_t ret = 0;

	return ret;
}

uint32_t Manager::recvHeartbeat(Message& msg)
{
	uint32_t ret = 0;

	// Send heart beat back to name server.
	// if this manager is the name server then recvHeartbeat will be overrided
	HeartbeatMsg& hb = dynamic_cast<HeartbeatMsg&>(msg);

	HeartbeatMsg* reply = new HeartbeatMsg();

	Location src = msg.getSrc();
	src.enqueueItem(reply);

	return ret;
}

void Manager::addSlot(Slot& slot, Message& signal)
{
	slot.connectSignal(signal);
	SlotMessageMap_t::iterator it = m_slotsMap.find(signal.getName());
	if (it != m_slotsMap.end())
	{
		(*it).second.push_back(slot);

	}
	else
	{
		m_slotsMap.insert(std::pair<std::string, SlotVec_t>(signal.getName(), { slot }));
	}
}

void Manager::StartRun()
{
	if (!m_runStarted)
	{
		m_runStarted = true;
		Start();
		while (1)
		{
			while (0 == turnSemaphore)
			{
				std::this_thread::yield();
			}
			std::lock_guard <std::mutex> lock(m_executionMutex);


			// Loop and receive msgs/data from queue
			bool terminate = !Run();


			if (terminate)
			{
				Stop();
				turnSemaphore = 0;
				break;
			}
			turnSemaphore = 0;
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
			while (1 == turnSemaphore)
			{
				std::this_thread::yield();
			}
			std::lock_guard <std::mutex> lock(m_executionMutex);


			// Loop and receive msgs/data from queue
			bool terminate = !ReceiveMsgs();
			if (terminate)
			{
				Stop();
				turnSemaphore = 1;
				break;
			}
			turnSemaphore = 1;


		}
	}
}

bool Manager::ReceiveMsgs()
{
	// Returning true will terminate the manager.
	// It is indicative of an error in processing
	bool ret = false;
	while (1)
	{

		bool status = true;
		Message* signal = m_location.dequeueItem(status);
		// TODO Need to figure out way to bring message to manager child
		// Maybe use something like QT signal/slot paradigm
		SlotVec_t slots = findSlots(signal);
		if (slots.empty() || nullptr == signal)
		{


			ret = true;
			break;
		}
		else
		{
			SlotVec_t::iterator it = slots.begin();
			SlotVec_t::iterator endIt = slots.end();

			while (it != endIt)
			{
				uint32_t retVal = (*it)(*signal);
				if (retVal < 0)
				{
					ret = false;
					break;
				}

				it++;
			}
		}
	}
	return ret;
}

Manager::SlotVec_t Manager::findSlots(Message* msg)
{

	SlotVec_t ret;
	if (nullptr != msg)
	{
		SlotMessageMap_t::iterator it = m_slotsMap.find(msg->getName());
		if (it != m_slotsMap.end())
		{
			ret = (it->second);
		}
	}
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