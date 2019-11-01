#pragma once
#include "Manager.h"
class MachineInterface : public Manager
{
public:
	

	// Manager Methods
	static MachineInterface* getMgr();

	uint32_t moveHandle(Message& msg);

protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	MachineInterface();
	~MachineInterface();

	static MachineInterface* ms_machineInterfacePtr;

	// (Software commanded) Machine Overrides
	bool stopMachine();

	// Motor Rates
	bool setFeedRate(double feedRate);

	// Positioning
	bool moveXAbs(double units);
	bool moveYAbs(double units);
	bool moveZAbs(double units);

	bool moveXRel(double units);
	bool moveYRel(double units);
	bool moveZRel(double units);

};

