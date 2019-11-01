#pragma once
#include "SysEnv.h"
#include <string>
#include <vector>
#include "Drivers/StepperMotor/Stepper.h"

// Forward Declarations


enum class Unit_t : uint8_t
{
	INCHES,
	MILLIMETER,
	MIL
};



enum class AxisName_t : uint8_t
{
	UNKNOWN,
	X_AXIS,
	Y_AXIS,
	Z_AXIS,
	A_AXIS,
	B_AXIS,
	C_AXIS
};

class AxisGeneric
{
public:
	typedef std::vector<Stepper> StepperVec_t;

	AxisGeneric() : 
		m_resolution(0),
		m_length(0),
		m_unitType(Unit_t::INCHES),
		m_name(AxisName_t::UNKNOWN)
	{}
	AxisGeneric(AxisName_t name, double length);
	~AxisGeneric();
	
	// Getters
	double getLength() const;
	const AxisName_t& getAxisName() const;
	double getResolution() const;
	Unit_t getUnitType() const;
	const StepperVec_t getSteppers() const;


	// Setters
	void setResolution(double resolution); 
	void setAxisName(const AxisName_t& name);
	void setLength(double length);
	void setUnitType(Unit_t unitType); 
	void setSteppers(const StepperVec_t steppers);

	// Validators
	bool isLengthValid(double len)
	{
		bool ret = false;
		if (len >= 0 && len <= 100)
		{
			ret = true;
		}

		return ret;
	}

	// Units dictated by resolution
	virtual void moveByUnit(uint32_t units); 
	
	// Absolute move dictated by measurement system
	virtual void moveAbsolute(double distance); 
	
	

private:

	// Since an axis can have a variable number of stepper motors
	// We leave the stepper members to be declared in the child class

	double m_resolution;
	double m_length;
	Unit_t m_unitType;
	AxisName_t m_name;


	// Since an axis can have a variable number of stepper motors
	// We leave the stepper members to be declared in the child class
	StepperVec_t m_stepperVec;
};

#include <MetaLib/Meta.h>

namespace meta
{


	template <>
	inline auto registerMembers<AxisGeneric>()
	{
		return members(
			member("m_resolution", &AxisGeneric::getResolution, &AxisGeneric::setResolution),
			member("m_length", &AxisGeneric::getLength, &AxisGeneric::setLength, &AxisGeneric::isLengthValid),
			member("m_unitType", &AxisGeneric::getUnitType, &AxisGeneric::setUnitType),
			member("m_name", &AxisGeneric::getAxisName, &AxisGeneric::setAxisName)


		);
	}

}