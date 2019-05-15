#include "ManagerTest.h"

ManagerTest::ExampleMgr* ManagerTest::ExampleMgr::m_exampleMgrPtr = nullptr;

ManagerTest::ManagerTest()
{
}


ManagerTest::~ManagerTest()
{
}

bool ManagerTest::runTest()
{
	ManagerTest::ExampleMgr::getMgr();
	

	return true;
}