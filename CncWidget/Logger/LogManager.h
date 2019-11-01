#pragma once
#include <Manager.h>

class LogManager : public Manager
{

public:


	// Manager Methods
	static LogManager* getMgr();

protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	LogManager();
	~LogManager();

	static LogManager* ms_logManagerPtr;

};

