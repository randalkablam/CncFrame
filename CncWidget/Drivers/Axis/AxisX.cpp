#include "AxisX.h"
#include "Drivers/StepperMotor/Stepper.h"



AxisX::AxisX(double length) :
	AxisGeneric(AxisName_t::X_AXIS, length)
{
}

AxisX::~AxisX()
{
}


void AxisX::moveByUnit(uint32_t units)
{
}

void AxisX::moveAbsolute(double distance)
{
}

