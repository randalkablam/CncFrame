#pragma once
#include <Manager.h>

// This manager will delegate the processing of images from the PNP's camera. It will
// then supply the results of this to interested parties (ie the GUI, the motion controller, etc tbd)
class CameraProc : public Manager
{
public:


	// Manager Methods
	static CameraProc* getMgr();

protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	CameraProc();
	~CameraProc();

	static CameraProc* ms_cameraProcPtr;

};

