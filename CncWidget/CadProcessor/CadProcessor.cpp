#include "CadProcessor.h"
#include "Utils/PnpDefs.h"

CadProcessor* CadProcessor::ms_cadProcessorPtr = CadProcessor::getMgr();

CadProcessor* CadProcessor::getMgr()
{
	if (nullptr == ms_cadProcessorPtr)
	{
		ms_cadProcessorPtr = new CadProcessor();


	}
	return ms_cadProcessorPtr;
}

void CadProcessor::Start()
{
}

bool CadProcessor::Run()
{
	return false;
}

void CadProcessor::Stop()
{
}

CadProcessor::CadProcessor() : 
	Manager(ManagerNames::CAD_PROCESSOR_NAME)
{
}

CadProcessor::~CadProcessor()
{
}
