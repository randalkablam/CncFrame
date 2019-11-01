#pragma once
#include <Message.h>
#include "Drivers/Axis/AxisGeneric.h"
#include "Drivers/Axis/AxisConfigMsg.h"
#include "Drivers/Valve/ValveConfigMsg.h"
#include "Drivers/Pump/PumpConfigMsg.h"

#include <vector>
#include <string>
#include "Location.h"

// This class will hold configuration data
Derive_Message_CRTP(ConfigurationMessage)
{
public:
	ConfigurationMessage();
	
	class NameServerConfig
	{
	public:
		std::string m_mnsAddr;
		uint16_t m_mnsPort;

	};

	
	NameServerConfig m_nameServerConfig;
	std::vector<Location> m_managers;

	AxisConfigMsg m_axisConfig;
	ValveConfigMsg m_valveConfig;
	PumpConfigMsg m_pumpConfig;

	std::string m_configurationName;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<ConfigurationMessage::NameServerConfig>()
	{
		return members(
			member("m_mnsAddr", &ConfigurationMessage::NameServerConfig::m_mnsAddr),
			member("m_mnsPort", &ConfigurationMessage::NameServerConfig::m_mnsPort)
		);
	}

	template <>
	inline auto registerMembers<ConfigurationMessage>()
	{
		return members(
			member("m_nameServerConfig", &ConfigurationMessage::m_nameServerConfig),
			member("m_managers", &ConfigurationMessage::m_managers),
			member("m_axisConfig", &ConfigurationMessage::m_axisConfig),
			member("m_valveConfig", &ConfigurationMessage::m_valveConfig),
			member("m_pumpConfig", &ConfigurationMessage::m_pumpConfig),
			member("m_configurationName", &ConfigurationMessage::m_configurationName)
		);
	}

}