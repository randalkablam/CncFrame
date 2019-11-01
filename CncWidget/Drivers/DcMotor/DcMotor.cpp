#include "DcMotor.h"

DcMotor::DcMotor()
{
}

DcMotor::DcMotor(std::string i2cName, uint8_t i2cDev, uint8_t i2cReg) :
	m_i2c(i2cName, i2cDev, i2cReg)
{
}

DcMotor::~DcMotor()
{
}

bool DcMotor::setSpeed(double rmpSpeed)
{
	return false;
}
