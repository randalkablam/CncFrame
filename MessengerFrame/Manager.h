#pragma once
#include <string>
#include "Priority.h"
#include "Location.h"
class Manager
{
public: 
	void StartRun();
	void StartMsgReader();
protected:
	Manager(std::string managerName);
	~Manager();

	virtual void Initialize() = 0;
	virtual bool Run() = 0;
	virtual void Terminate() = 0;

	std::string getName();
	
	Location m_location;
private:

	std::string m_managerName;
	Priority m_priority;

	bool ReceiveMsgs();
	bool m_msgReaderStarted;
	bool m_runStarted;
	uint32_t tidRun;
	uint32_t tidMsg;
	
};

static uint32_t ThreadMsg(void* ptr);
static uint32_t ThreadRun(void* ptr);


