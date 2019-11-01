#include "MachineInterface.h"
#include "Utils/PnpDefs.h"
#include <NameServer.h>
MachineInterface* MachineInterface::ms_machineInterfacePtr = MachineInterface::getMgr();


MachineInterface::MachineInterface() :
	Manager(ManagerNames::MACHINE_INTERFACE_NAME)
{
}


MachineInterface::~MachineInterface()
{
}

bool MachineInterface::stopMachine()
{
	return false;
}

bool MachineInterface::setFeedRate(double feedRate)
{
	return false;
}


bool MachineInterface::moveXAbs(double units)
{
	return false;
}

bool MachineInterface::moveYAbs(double units)
{
	return false;
}

bool MachineInterface::moveZAbs(double units)
{
	return false;
}

bool MachineInterface::moveXRel(double units)
{
	return false;
}

bool MachineInterface::moveYRel(double units)
{
	return false;
}

bool MachineInterface::moveZRel(double units)
{
	return false;
}






// Basic Manager Methods
MachineInterface* MachineInterface::getMgr()
{
	if (nullptr == ms_machineInterfacePtr)
	{
		ms_machineInterfacePtr = new MachineInterface();


	}
	return ms_machineInterfacePtr;
}

uint32_t MachineInterface::moveHandle(Message& msg)
{
	return uint32_t();
}


	void MachineInterface::Start()
	{
		std::cout << getName() << " Start()" << std::endl;
		NameServer* ns = NameServer::getNameServer();
		if (nullptr != ns)
		{
			Location* gpioMgr = ns->getLocation(ManagerNames::GPIO_MANAGER_NAME);
			
		}
	}
	bool MachineInterface::Run()
	{
		std::cout << getName() << " Run()" << std::endl;
		return true;
	}
	void MachineInterface::Stop()
	{
		std::cout << getName() << " Stop()" << std::endl;
	}
