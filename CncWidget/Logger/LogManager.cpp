#include "LogManager.h"
#include "Utils/PnpDefs.h"

LogManager* LogManager::ms_logManagerPtr = LogManager::getMgr();;


LogManager::LogManager() :
	Manager(ManagerNames::LOG_MANAGER_NAME)
{
}


LogManager::~LogManager()
{
}




// Basic Manager Methods
LogManager* LogManager::getMgr()
{
	if (nullptr == ms_logManagerPtr)
	{
		ms_logManagerPtr = new LogManager();


	}
	return ms_logManagerPtr;
}


void LogManager::Start()
{
	std::cout << getName() << " Initialize()" << std::endl;
}
bool LogManager::Run()
{
	std::cout << getName() << " Run()" << std::endl;
	return true;
}
void LogManager::Stop()
{
	std::cout << getName() << " Terminate()" << std::endl;
}


