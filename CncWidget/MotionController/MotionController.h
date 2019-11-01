#pragma once
#include <Manager.h>
class MotionController : public Manager
{

public:


	// Manager Methods
	static MotionController* getMgr();

protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	static MotionController* ms_motionControllerPtr;

	MotionController();
	~MotionController();

};