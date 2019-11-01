#pragma once
#include "Drivers/DriverBase.h"
#include "OsEnv.h"
#include <vector>
#include <string>

class I2cDriver : public DriverBase
{


public:
	I2cDriver() :
		m_device("")
	{}
	I2cDriver(std::string name) :
		m_device(name)
	{}

	void setDevice(const std::string& dev);
	const std::string& getDevice() const;

	int32_t writeByte(uint8_t dev, uint8_t reg, uint8_t val);
	int32_t writeMultiByte(uint8_t dev, uint8_t reg, std::vector<uint8_t> &bytes);

	int32_t readByte(uint8_t dev, uint8_t reg, uint8_t& val);

private:

	int32_t openDevice(uint8_t &fd);
	int32_t configDevice(uint8_t fd, uint8_t dev);
	int32_t closeDevice(uint8_t fd);


	std::string m_device;

};
class I2cSet
{
public:
	I2cSet(std::string name, uint8_t dev, uint8_t reg)
		: m_i2c(I2cDriver(name)),
		  m_devAddr(dev),
		  m_regAddr(reg)
	{ }
	I2cSet() {}
	I2cDriver m_i2c;
	uint8_t m_devAddr;
	uint8_t m_regAddr;
};
#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<I2cDriver>()
	{
		return members(
			member("m_device", &I2cDriver::getDevice, &I2cDriver::setDevice)
		);
	}
	template <>
	inline auto registerMembers<I2cSet>()
	{
		return members(
			member("m_i2c", &I2cSet::m_i2c),
			member("m_devAddr", &I2cSet::m_devAddr),
			member("m_regAddr", &I2cSet::m_regAddr)
		);
	}
}
