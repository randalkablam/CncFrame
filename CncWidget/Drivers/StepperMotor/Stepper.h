#pragma once
#include <string>
#include "Drivers/I2C/I2cDriver.h"
#include "Drivers/GPIO/GpioDriver.h"
enum class StepSize_t : uint8_t
{
	ONE_SIXTY_FOURTH,
	ONE_THIRTY_SECOND,
	ONE_SIXTEENTH,
	EIGHTH,
	QUARTER,
	HALF,
	FULL
};

enum class StepDirection_t : uint8_t
{
	FORWARD,
	REVERSE
};



const double MIN_PULSE_WIDTH = 2.5 / 1000000; // 2.5 us
class Stepper
{
public:
    Stepper(void);

	Stepper(I2cSet& eni2c, I2cSet& dirI2c);

    ~Stepper(void);

	bool Initialize(GpioDriver* pulGpio);

	void setDirection(StepDirection_t direction);
	StepDirection_t getDirection() const;

	void setDriver(GpioDriver* driver);
	GpioDriver* getDriver(void) const;

	void setEnI2c(const I2cSet& dev);
	const I2cSet& getEnI2c() const;

	void setDirI2c(const I2cSet& dev);
	const I2cSet& getDirI2c() const;
	
	void step(double frequency, StepSize_t size = StepSize_t::FULL);

	void stepN(double frequency, uint16_t n, StepSize_t size = StepSize_t::FULL);

private:
	
	StepDirection_t m_direction;
	
	I2cSet m_enI2c;
	I2cSet m_dirI2c;
	
	// if the stepper motor is not initialized then this will be null
	GpioDriver *m_pulGpio;

	bool m_isInit;

};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<Stepper>()
	{
		return members(
			member("m_direction", &Stepper::getDirection, &Stepper::setDirection),
			member("m_enI2c", &Stepper::getEnI2c, &Stepper::setEnI2c),
			member("m_dirI2c", &Stepper::getDirI2c, &Stepper::setDirI2c)
		);
	}

}

