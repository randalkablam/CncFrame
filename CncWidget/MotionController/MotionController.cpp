#include "MotionController.h"
#include "Utils/PnpDefs.h"

MotionController* MotionController::ms_motionControllerPtr = MotionController::getMgr();


MotionController* MotionController::getMgr()
{
	if (nullptr == ms_motionControllerPtr)
	{
		ms_motionControllerPtr = new MotionController();


	}
	return ms_motionControllerPtr;
}

void MotionController::Start()
{
}

bool MotionController::Run()
{
	bool ret = false;
	return ret;
}

void MotionController::Stop()
{
}

MotionController::MotionController() : 
	Manager(ManagerNames::MOTION_CONTROLLER_NAME)
{
}

MotionController::~MotionController()
{
}
