#include "NameServer.h"
#include "ThreadManager.h"
NameServer* NameServer::m_nameServerPtr = nullptr;

NameServer* NameServer::getNameServer()
{
	if (nullptr == m_nameServerPtr)
	{
		m_nameServerPtr = new NameServer();


	}
	return m_nameServerPtr;
}

NameServer::NameServer() :
	m_isMNS(checkIfMns()),
	m_locationMap(),
	m_nsLocation()
{
	ThreadManager* tm = ThreadManager::getThreadManager();
	tm->createThread(NameServerProc, nullptr);

}


bool NameServer::checkIfMns()
{
	bool ret = false;

	return ret;
}

NameServer::~NameServer()
{
}


bool NameServer::RegisterLocation(Location& loc, const std::string managerName)
{
	bool ret = false;

	return ret;
}


bool NameServer::RegisterObject(DataItem& d)
{
	bool ret = false;

	return ret;

}


Location NameServer::getLocation(const std::string& name) 
{
	Location temp;//TODO
	return temp;
}


std::string NameServer::getName(const Location& loc) 
{
	return "";

}

uint32_t NameServer::NameServerProc(void* param)
{
	bool ret = false;
	bool isMns = NameServer::getNameServer()->checkIfMns();
	if (isMns)
	{
		// Is MNS. Start Server to listen for name server clients
	}
	else
	{
		// Is Not MNS. Start Client to connect to MNS

	}
	return ret;
}