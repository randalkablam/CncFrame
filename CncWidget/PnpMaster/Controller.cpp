#include "Controller.h"
#include "Utils/PnpDefs.h"

Controller* Controller::ms_controllerPtr = Controller::getMgr();

Controller* Controller::getMgr()
{
	if (nullptr == ms_controllerPtr)
	{
		ms_controllerPtr = new Controller();


	}
	return ms_controllerPtr;
}

void Controller::Start()
{
}

bool Controller::Run()
{
	return false;
}

void Controller::Stop()
{
}

Controller::Controller() :
	Manager(ManagerNames::CONTROLLER_NAME)
{
}

Controller::~Controller()
{
}
