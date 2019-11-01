#include "AxisGeneric.h"
#include "Drivers/StepperMotor/Stepper.h"



AxisGeneric::AxisGeneric(AxisName_t name, double length) :
	m_name(name),
	m_length(length)
{
}

AxisGeneric::~AxisGeneric()
{
}

double AxisGeneric::getLength() const
{
	return m_length;
}

const AxisName_t& AxisGeneric::getAxisName() const
{
	return m_name;
}

double AxisGeneric::getResolution() const
{
	return m_resolution;
}

Unit_t AxisGeneric::getUnitType() const
{
	return m_unitType;
}

const AxisGeneric::StepperVec_t AxisGeneric::getSteppers() const
{
	return m_stepperVec;
}

void AxisGeneric::setResolution(double resolution)
{
	// TOOD check if resolution is within min/max possible values
	m_resolution = resolution;
}

void AxisGeneric::setAxisName(const AxisName_t& name)
{
	m_name = name;
}

void AxisGeneric::setLength(double length)
{
	m_length = length;
}

void AxisGeneric::setUnitType(Unit_t unitType)
{
	m_unitType = unitType;
}

void AxisGeneric::setSteppers(const StepperVec_t steppers)
{
	m_stepperVec = steppers;
}

void AxisGeneric::moveByUnit(uint32_t units)
{
}

void AxisGeneric::moveAbsolute(double distance)
{
}

