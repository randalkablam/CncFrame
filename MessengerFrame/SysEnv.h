#pragma once
// This file defines system level constants - i.e. the ipaddresses/ports of mns and local managers
// Managers communicate across processors using name servers. Master Name Server is used to find the location of managers 
// on different processors and to route data/messages.
#include "OsEnv.h"
#include <string>

namespace SYS_ENV
{
	extern const uint16_t MNS_PORT;
	extern const uint16_t LOCAL_PORT;

	extern const std::string MNS_IP;
	extern const std::string LOCAL_IP;


}