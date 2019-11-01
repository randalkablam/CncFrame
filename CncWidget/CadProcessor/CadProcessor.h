#pragma once
#include <Manager.h>
class CadProcessor : public Manager
{

public:


	// Manager Methods
	static CadProcessor* getMgr();

protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	CadProcessor();
	~CadProcessor();

	static CadProcessor* ms_cadProcessorPtr;

};

