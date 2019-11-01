#pragma once
#include <Manager.h>

// This class will monitor system resources and report any excessive use. This is 
// a BIT test of sorts for resource management/profiler.
class ResourceManager : public Manager
{

public:


	// Manager Methods
	static ResourceManager* getMgr();

protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	ResourceManager();
	~ResourceManager();

	static ResourceManager* ms_resourceManagerPtr;

};

