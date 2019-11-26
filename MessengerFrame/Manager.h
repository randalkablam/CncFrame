#pragma once
#include <string>
#include <map>
#include "Message.h"
#include "Priority.h"
#include "Slot.h"
#include "Location.h"
#include <mutex>
class Manager
{
public: 
	void StartRun();
	void StartMsgReader();
	Location m_location;
	LocationMailBox m_mailbox;
	std::string getName();

	void StartManager();

protected:
	Manager(const std::string& managerName);
	Manager(const std::string& managerName, Location loc);

	~Manager();

	virtual void Start() = 0;
	virtual bool Run() = 0;
	virtual void Stop() = 0;

	bool sendMsg(Message& msg, Location& loc);

	virtual uint32_t recvCmd(Message& msg);
	
	virtual uint32_t recvHeartbeat(Message& msg);

	void addSlot(Slot& slot, Message& signal);


private:

	std::string m_managerName;
	Priority m_priority;

	bool ReceiveMsgs();
	bool m_msgReaderStarted;
	bool m_runStarted;
	uint32_t tidRun;
	uint32_t tidMsg;
	
	std::mutex m_executionMutex;
	std::condition_variable m_condVar;

	// A manager can have multiple slots for a given signal and
	// a slot can have multiple signals (messages) associated with it
	typedef std::vector<Slot> SlotVec_t;
	typedef std::map<std::string, SlotVec_t> SlotMessageMap_t;
	SlotMessageMap_t m_slotsMap;

	SlotVec_t findSlots(Message* msg);

	int32_t turnSemaphore;

	bool m_isStarted;
	


};

static uint32_t ThreadMsg(void* ptr);
static uint32_t ThreadRun(void* ptr);

