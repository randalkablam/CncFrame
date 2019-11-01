#include "AxisZ.h"
#include "Drivers/StepperMotor/Stepper.h"



AxisZ::AxisZ(double length) :
	AxisGeneric(AxisName_t::Z_AXIS, length)
{
}

AxisZ::~AxisZ()
{
}


void AxisZ::moveByUnit(uint32_t units)
{
}

void AxisZ::moveAbsolute(double distance)
{
}

