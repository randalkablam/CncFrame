#include "ConfigurationMgr.h"
#include "Utils/PnpDefs.h"
#include "Marshaller.h"
#include "FileManager/FileManager.h"


ConfigurationMgr* ConfigurationMgr::ms_configurationMgrPtr = ConfigurationMgr::getMgr();

ConfigurationMgr* ConfigurationMgr::getMgr()
{
	if (nullptr == ms_configurationMgrPtr)
	{
		ms_configurationMgrPtr = new ConfigurationMgr();


	}
	return ms_configurationMgrPtr;
}

void ConfigurationMgr::Start()
{
}

bool ConfigurationMgr::Run()
{
	return false;
}

void ConfigurationMgr::Stop()
{
}

ConfigurationMgr::ConfigurationMgr() :
	Manager(ManagerNames::CONFIGURATION_MGR_NAME)
{
	Slot* sl = new Slot(this);
	sl->registerSlot(std::bind(&ConfigurationMgr::saveConfiguration, this, std::placeholders::_1));
	ConfigurationMessage msg;
	addSlot(*sl, msg);
}

ConfigurationMgr::~ConfigurationMgr()
{
}

uint32_t ConfigurationMgr::saveConfiguration(Message& msg)
{
	uint32_t ret = 0;
	ConfigurationMessage& configMsg = dynamic_cast<ConfigurationMessage&>(msg);
	Marshaller* marshall = Marshaller::getMarshaller();

	std::vector<uint8_t> *rawMsg = marshall->toByteStream(configMsg);
	
	FileManager::writeFile(configMsg.m_configurationName, *rawMsg);

	delete rawMsg;


	return ret;
}
