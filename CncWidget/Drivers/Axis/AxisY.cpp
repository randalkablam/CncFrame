#include "AxisY.h"
#include "Drivers/StepperMotor/Stepper.h"



AxisY::AxisY(double length) :
	AxisGeneric(AxisName_t::Y_AXIS, length)
{
}

AxisY::~AxisY()
{
}


void AxisY::moveByUnit(uint32_t units)
{
}

void AxisY::moveAbsolute(double distance)
{
}

