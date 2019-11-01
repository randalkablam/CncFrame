#pragma once
#include "SysEnv.h"
#include <string>
#include "AxisGeneric.h"
#include <vector>

// Forward Declarations
class Stepper;


class AxisX : public AxisGeneric
{
public:
	AxisX(double length);
	~AxisX();

	
	// Units dictated by resolution
	virtual void moveByUnit(uint32_t units); 
	
	// Absolute move dictated by measurement system
	virtual void moveAbsolute(double distance); 
	
	

private:




};

