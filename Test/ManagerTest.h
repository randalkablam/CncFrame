#pragma once

#include "Manager.h"
#include <typeinfo>
#include <iostream>
class ManagerTest
{
public:
	ManagerTest();
	~ManagerTest();

	bool runTest();


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
		

	private:
		static ExampleMgr* m_exampleMgrPtr;
		ExampleMgr() :
			Manager(typeid(ExampleMgr).name())
		{
		
		}
		virtual void Initialize()
		{
			std::cout << getName() << " Initialize()" << std::endl;
		}
		virtual bool Run()
		{
			std::cout << getName() << " Run()" << std::endl;
			return false;
		}
		virtual void Terminate()
		{
			std::cout << getName() << " Terminate()" << std::endl;
		}

		
	


	};

};

