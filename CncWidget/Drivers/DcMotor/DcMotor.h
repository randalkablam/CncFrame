#pragma once
#include "SysEnv.h"
#include "Drivers/I2C/I2cDriver.h"
class DcMotor
{
public:
	DcMotor();
	DcMotor(std::string i2cName, uint8_t i2cDev, uint8_t i2cReg);
	~DcMotor();

	bool setSpeed(double rmpSpeed);
	
	I2cSet m_i2c;

};



#include "MetaLib/Meta.h"
namespace meta
{


	template <>
	inline auto registerMembers<DcMotor>()
	{
		return members(
			member("m_i2c", &DcMotor::m_i2c)
		);
	}

}