#include "ManagerTest.h"
ExampleMgr* ExampleMgr::m_exampleMgrPtr = nullptr;
ExampleMgr2* ExampleMgr2::m_exampleMgrPtr2 = nullptr;

ManagerTest::ManagerTest()
{
	ExampleMgr2* ptr2 = ExampleMgr2::getMgr();
	ExampleMgr* ptr1 = ExampleMgr::getMgr();

	ptr2->StartManager();
	ptr1->StartManager();
}


ManagerTest::~ManagerTest()
{
}

bool ManagerTest::runTest()
{
	
	ExampleMgr2* ptr2 = ExampleMgr2::getMgr();
	ExampleMgr* ptr1 = ExampleMgr::getMgr();
	std::cout << ptr2->getName() << " " << ptr1->getName() << std::endl;
	ptr1->send(ptr2->m_location);
	
	return true;
}

uint32_t ExampleMgr2::test( Message& msg)
{
	ExampleMsg& exMsg = dynamic_cast<ExampleMsg&>(msg);
	std::cout << msg.getName() << std::endl;
	return 0;
}

ExampleMgr2::ExampleMgr2() :
	Manager("ExampleMgr2")
{
	Slot *sl = new Slot(this);
	sl->registerSlot(std::bind(&ExampleMgr2::test, this, std::placeholders::_1));
	ExampleMsg msg;
	addSlot(*sl, msg);
}