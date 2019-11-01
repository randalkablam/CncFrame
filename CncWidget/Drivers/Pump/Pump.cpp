#include "Pump.h"

Pump::Pump(std::string i2cName, uint8_t i2cDev, uint8_t i2cReg) :
	m_dcMotor(i2cName, i2cDev, i2cReg)
{
}

Pump::Pump()
{
}

Pump::~Pump()
{
}

const DcMotor& Pump::getDcMotor() const
{
	return m_dcMotor;
}

void Pump::setDcMotor(const DcMotor& dc)
{
	m_dcMotor = dc;
}
