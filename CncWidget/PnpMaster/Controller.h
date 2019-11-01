#pragma once
#include <Manager.h>
class Controller : public Manager
{

public:


	// Manager Methods
	static Controller* getMgr();

protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	Controller();
	~Controller();

	static Controller* ms_controllerPtr;

};

