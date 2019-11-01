#include "Drivers/StepperMotor/Stepper.h"
#include "TimeUtils.h"
#include "Drivers/I2C/I2cDriver.h"
Stepper::Stepper(void) :
	m_pulGpio(nullptr),
	m_isInit(false)
{

}

Stepper::Stepper(I2cSet& eni2c, I2cSet& dirI2c) :
	m_enI2c(),
	m_dirI2c(),
	m_pulGpio(nullptr),
	m_isInit(false)
{
}


Stepper::~Stepper(void)
{

}

bool Stepper::Initialize(GpioDriver* pulGpio)
{

	bool ret = false;
	// Don't want to reinit a stepper motor driver
	// and don't want to init it with a nullptr gpio driver
	// If you want to reinit a stepper motor make a new one/delete
	// the old one
	if (nullptr != pulGpio && false == m_isInit)
	{

		m_pulGpio = pulGpio;
		ret = true;
		m_isInit = true;

	}

	return ret;
}

void Stepper::setDirection(StepDirection_t direction)
{
}

StepDirection_t Stepper::getDirection() const
{
	return m_direction;
}

void Stepper::setDriver(GpioDriver* driver)
{
	m_pulGpio = driver;
}
 
GpioDriver* Stepper::getDriver(void) const
{
	return m_pulGpio;
}

void Stepper::setEnI2c(const I2cSet& dev)
{
	m_enI2c = dev;
}
const I2cSet & Stepper::getEnI2c() const
{
	return m_enI2c;
}

void Stepper::setDirI2c(const I2cSet& dev)
{
	m_dirI2c = dev;
}
const I2cSet& Stepper::getDirI2c() const
{
	return m_dirI2c;
}

void Stepper::step(double frequency, StepSize_t size) // Frequency in hertz
{
	// TODO make duty cycle part of this...need to see if duty cycle has impact on torque/speed


	// Up part of cycle

	m_pulGpio->setValue(true);
	if (1 / (2 * frequency) >= MIN_PULSE_WIDTH)
	{
		OsSleep(1 / (2 * frequency));
	}
	else
	{
		OsSleep(MIN_PULSE_WIDTH * 1000000000);
	}

	// Down part of cycle
	m_pulGpio->setValue(false);

	if (1 / (2 * frequency) >= MIN_PULSE_WIDTH)
	{
		OsSleep(1 / (2 * frequency));
	}
	else
	{
		OsSleep(MIN_PULSE_WIDTH * 1000000000);
	}

}

void Stepper::stepN(double frequency, uint16_t n, StepSize_t size)
{
	// perhaps a naive way to do this
	for (uint16_t i = 0; i < n; i++)
	{

		step(frequency, size);

	}

}
