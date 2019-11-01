#pragma once

#include "Drivers/DriverBase.h"
#include "Drivers/I2C/I2cDriver.h"

class Valve : public DriverBase
{
public:
	Valve(std::string i2cName, uint8_t i2cDev, uint8_t i2cReg);
	Valve();
	~Valve();

	I2cSet m_i2c;
};






#include "MetaLib/Meta.h"
namespace meta
{


	template <>
	inline auto registerMembers<Valve>()
	{
		return members(
			member("m_i2c", &Valve::m_i2c)
		);
	}

}