#include "ResourceManager.h"
#include "Utils/PnpDefs.h"

ResourceManager* ResourceManager::ms_resourceManagerPtr = ResourceManager::getMgr();

ResourceManager* ResourceManager::getMgr()
{
	if (nullptr == ms_resourceManagerPtr)
	{
		ms_resourceManagerPtr = new ResourceManager();


	}
	return ms_resourceManagerPtr;
}

void ResourceManager::Start()
{
}

bool ResourceManager::Run()
{
	return false;
}

void ResourceManager::Stop()
{
}

ResourceManager::ResourceManager() :
	Manager(ManagerNames::RESOURCE_MANAGER_NAME)
{
}

ResourceManager::~ResourceManager()
{
}
