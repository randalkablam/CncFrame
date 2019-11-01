#pragma once
#include <Manager.h>
#include "ConfigurationMessage.h"
// This manager will hold all configuration files read in as xml and converted to
// Message's. It will send out config data on request.
class ConfigurationMgr : public Manager
{
public:


	// Manager Methods
	static ConfigurationMgr* getMgr();

protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	ConfigurationMgr();
	~ConfigurationMgr();

	uint32_t saveConfiguration(Message& msg);


	static ConfigurationMgr* ms_configurationMgrPtr;

};

