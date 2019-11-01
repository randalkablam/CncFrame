#include "Valve.h"

Valve::Valve(std::string i2cName, uint8_t i2cDev, uint8_t i2cReg) :
	m_i2c(i2cName, i2cDev, i2cReg)
{
}

Valve::Valve()
{
}

Valve::~Valve()
{
}
