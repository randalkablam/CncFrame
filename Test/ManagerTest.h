#pragma once

#include "Manager.h"
#include <typeinfo>
#include "Slot.h"
#include <iostream>
class ManagerTest
{
public:
	ManagerTest();
	~ManagerTest();

	bool runTest();
	
	
};

class ExampleMsg : public Message
{
public:
	ExampleMsg() :
		Message()
	{

	}

	std::string m_data;

};

class ExampleMgr : public Manager
{
public:
	static ExampleMgr* getMgr()
	{
		if (nullptr == m_exampleMgrPtr)
		{
			m_exampleMgrPtr = new ExampleMgr();


		}
		return m_exampleMgrPtr;
	}

	void send(Location& loc)
	{
		ExampleMsg* msg = new ExampleMsg();
		msg->m_data = "Hello world;\n";
		loc.enqueueItem(msg);
	}
private:
	static ExampleMgr* m_exampleMgrPtr;
	ExampleMgr() :
		Manager("ExampleMgr")
	{

	}
	virtual void Start()
	{
		std::cout << getName() << " Initialize()" << std::endl;
	}
	virtual bool Run()
	{
		std::cout << getName() << " Run()" << std::endl;
		return true;
	}
	virtual void Stop()
	{
		std::cout << getName() << " Terminate()" << std::endl;
	}





};
class ExampleMgr2 : public Manager
{
public:
	static ExampleMgr2* getMgr()
	{
		if (nullptr == m_exampleMgrPtr2)
		{
			m_exampleMgrPtr2 = new ExampleMgr2();


		}
		return m_exampleMgrPtr2;
	}


private:
	static ExampleMgr2* m_exampleMgrPtr2;
	ExampleMgr2();
	virtual void Start()
	{
		std::cout << getName() << " Initialize()" << std::endl;
	}
	virtual bool Run()
	{
		std::cout << getName() << " Run()" << std::endl;
		return true;
	}
	virtual void Stop()
	{
		std::cout << getName() << " Terminate()" << std::endl;
	}


	uint32_t test(Message& msg);




};