#pragma once
#include "SysEnv.h"
#include <string>
#include "AxisGeneric.h"
#include <vector>

// Forward Declarations
class Stepper;


class AxisZ : public AxisGeneric
{
public:
	AxisZ(double length);
	~AxisZ();

	
	// Units dictated by resolution
	virtual void moveByUnit(uint32_t units); 
	
	// Absolute move dictated by measurement system
	virtual void moveAbsolute(double distance); 
	
	

private:
	


};

