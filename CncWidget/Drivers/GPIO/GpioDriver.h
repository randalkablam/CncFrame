#pragma once
#include "Drivers/DriverBase.h"
#include <OsEnv.h>
#include <map>
#include <Manager.h>
#include <Location.h>
class GpioDriver : public DriverBase
{

public:

	

	enum class Direction_t
	{
		UNKNOWN,
		IN_DIR,
		OUT_DIR,
	};

	const std::string BASE_DIR = "/sys/class/gpio/gpio";
	const std::string EXPORT_FILE = "/sys/class/gpio/export";
	bool getValue();
	void setValue(bool isHigh);

	Direction_t getDirection();
	void setDirection(Direction_t dir);
	inline uint16_t getHandle()
	{
		return m_fd;
	}


	GpioDriver(uint16_t pin);
private:

	void exportPin(uint16_t pin);

	int16_t m_fd;
	uint16_t m_pin;
};

