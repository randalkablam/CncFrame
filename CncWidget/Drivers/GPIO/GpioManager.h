#pragma once
#include "Drivers/DriverBase.h"
#include <OsEnv.h>
#include <map>
#include <Manager.h>
#include <Location.h>
#include "GpioDriver.h"

class GpioManager : public Manager
{

public:

	static GpioManager* getMgr();

	bool addGpioListener(uint16_t pin, Location& loc);
	bool removeGpioListener(uint16_t pin, Location& loc);

	uint32_t gpioAddMsgSlot(Message& msg);
	uint32_t gpioRemoveMsgSlot(Message& msg);
	uint32_t gpioLockRequestSlot(Message& msg);

private:
	GpioManager();

	static GpioManager* ms_gpioManagerPtr;

	virtual void Start();
	virtual bool Run();
	virtual void Stop();

	typedef std::map<uint16_t, GpioDriver*> GpioPinMap_t;
	GpioPinMap_t m_pinDriverMap;

	typedef std::vector<Location> LocationVec_t;
	typedef std::map<uint16_t, LocationVec_t> GpioLocationMap_t;

	bool inLocationVector(Location& loc, LocationVec_t& locVec);

	GpioLocationMap_t m_gpioLocationMap;

	fd_set m_pinDescipSet;

	void createSlots();
	GpioDriver* createDriver(uint16_t pin, bool listen);
};

