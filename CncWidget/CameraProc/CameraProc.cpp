#include "CameraProc.h"
#include "Utils/PnpDefs.h"

CameraProc* CameraProc::ms_cameraProcPtr = CameraProc::getMgr();

CameraProc* CameraProc::getMgr()
{
	if (nullptr == ms_cameraProcPtr)
	{
		ms_cameraProcPtr = new CameraProc();


	}
	return ms_cameraProcPtr;
}

void CameraProc::Start()
{
}

bool CameraProc::Run()
{
	return false;
}

void CameraProc::Stop()
{
}

CameraProc::CameraProc() : 
	Manager(ManagerNames::CAMERA_PROC_NAME)
{
}

CameraProc::~CameraProc()
{
}
