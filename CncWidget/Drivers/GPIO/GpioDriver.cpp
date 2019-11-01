#include "GpioDriver.h"
#include <iostream>
#include <fcntl.h>
#ifdef OS_LINUX
#include <unistd.h>
#elif defined OS_WINDOWS
#include <io.h>
#endif
bool GpioDriver::getValue()
{
	bool ret = false;
	std::string filename = BASE_DIR + std::to_string(m_pin) + "/value";
#if 0
	int32_t fd = open(filename.c_str(), O_RDONLY);

	if (fd > 0)
	{
		char buf[2];
		read(fd, buf, 2);
		if ('1' == buf[0])
		{
			ret = true;
		}
		else if ('0' == buf[0])
		{
			ret = false;
		}
	}
#endif
	return ret;
}

void GpioDriver::setValue(bool isHigh)
{
	std::string filename = BASE_DIR + std::to_string(m_pin) + "/value";
#if 0
	int32_t fd = open(filename.c_str(), O_RDWR);

	if (fd > 0)
	{
		if (isHigh)
		{
			char buf[2] = "1";
			write(fd, buf, 2);
		}
		else
		{
			char buf[2] = "0";
			write(fd, buf, 2);
		}
		close(fd);
	}
#endif
}

GpioDriver::Direction_t GpioDriver::getDirection()
{
	Direction_t ret = Direction_t::UNKNOWN;
#if 0
	std::string filename = BASE_DIR + std::to_string(m_pin) + "/direction";
	int32_t fd = open(filename.c_str(), O_RDONLY);
	
	if (fd > 0)
	{
		char buf[2];
		read(fd, buf, 2);
		if ('1' == buf[0])
		{
			ret = Direction_t::OUT_DIR;
		}
		else if ('0' == buf[0])
		{
			ret = Direction_t::IN_DIR;
		}
	}
#endif
	return ret;
}

void GpioDriver::setDirection(Direction_t dir)
{
#if 0
	std::string filename = BASE_DIR + std::to_string(m_pin) + "/direction";
	int32_t fd = open(filename.c_str(), O_RDWR);
	if (fd > 0)
	{
		if (Direction_t::IN_DIR == dir)
		{
			char buf[4] = "in";
			write(fd, buf, 3);
		}
		else if (Direction_t::OUT_DIR == dir)
		{
			char buf[4] = "out";
			write(fd, buf, 4);
		}
		// else do nothing
	
		close(fd);
	}
#endif
}

GpioDriver::GpioDriver(uint16_t pin) : 
	m_fd(0),
	m_pin(pin)
{
#if 0
	// TODO open once at construction instead of for every write/read
	//std::string filename = BASE_DIR + std::to_string(pin) + "/value";
	//m_fd = open(filename.c_str(), O_RDONLY);

	exportPin(pin);

#endif
}

void GpioDriver::exportPin(uint16_t pin)
{
#if 0
	std::string pinStr = std::to_string(pin);

	int32_t fd = open(EXPORT_FILE.c_str(), O_RDWR);
	if (fd > 0)
	{
		
		int32_t sz = write(fd, pinStr.c_str(), pinStr.length() + 1);

		if (sz != (pinStr.length() + 1))
		{
			// TODO error logging

		}
		close(fd);
	}
#endif

}

