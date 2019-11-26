#include "NameServer.h"
#include "ThreadManager.h"
#include "SysEnv.h"
#include "MnsClient.h"
#include "MnsServer.h"
#include "HeartbeatMsg.h"


NameServer* NameServer::m_nameServerPtr = NameServer::getNameServer();
const std::string NameServer::INVALID_IP = "";
NameServer* NameServer::getNameServer()
{
	if (nullptr == m_nameServerPtr)
	{
		m_nameServerPtr = new NameServer();


	}
	return m_nameServerPtr;
}

LocationMailBox* NameServer::getMailBox(Location* loc)
{
	LocationMailBox* ret = nullptr;
	auto it = m_mailBoxMap.find(loc);
	if (it != m_mailBoxMap.end())
	{
		ret = it->second;
	}

	return ret;
}

NameServer::NameServer() :
	Manager("NameServer", Location(SYS_ENV::LOCAL_IP, SYS_ENV::LOCAL_PORT, "NameServer")),
	m_isMNS(checkIfMns()),
	m_locationMap(),
	m_nsLocation(SYS_ENV::LOCAL_IP, SYS_ENV::LOCAL_PORT, "NameServer"),
	m_nsMailBox(),
	m_dataMap(),
	m_mailBoxMap(),
	m_locationAliveMap()
{
	ThreadManager* tm = ThreadManager::getThreadManager();
	tm->createThread(NameServerProc, nullptr);


}


bool NameServer::checkIfMns()
{
	bool ret = false;

	return ret;
}

void NameServer::registerRemoteDataItem(DataItem& di)
{
	// If we are the mns, we will have to forward this entry to other name servers
	if (checkIfMns())
	{

	}
	else
	{

	}
		
}

NameServer::~NameServer()
{
}


bool NameServer::RegisterLocation(Location* loc, LocationMailBox* mailBox, const std::string managerName)
{
	bool ret = false;


	if (nullptr != loc)
	{
		// Don't want to add to map if the pair already exists in some capacity
		if (getName(loc) == "" && getLocation(managerName) == nullptr)
		{

			m_nameMap.insert(std::pair<std::string, Location*>({ managerName, loc }));
			m_locationMap.insert(std::pair<Location*, std::string>({ loc, managerName }));
			m_mailBoxMap.insert(std::pair<Location*, LocationMailBox*>({ loc, mailBox }));
			m_locationAliveMap.push_back(std::pair<Location, bool>({*loc, true}));


			ret = true;
		}
	}

	return ret;
}


bool NameServer::RegisterObject(DataItem& d)
{
	bool ret = false;

	// Don't want to try to add data item with uid already present in map.
	if (m_dataMap.find(d.getUid()) == m_dataMap.end())
	{
		
		registerRemoteDataItem(d);

		m_dataMap.insert(std::pair<uint32_t, DataItem>({ d.getUid(), d }));
		
		
		
		

		ret = true;
		
	}
	return ret;

}


Location* NameServer::getLocation(const std::string& name)
{
	Location* ret = nullptr;
	NameLocationMap_t::iterator it = m_nameMap.find(name);
	if (it != m_nameMap.end())
	{
		ret = it->second;
	}
	return ret;
}

uint32_t NameServer::recvHeartbeat(Message& msg)
{

	HeartbeatMsg& hb = dynamic_cast<HeartbeatMsg&>(msg);

	Location src = hb.getSrc();
	

	return uint32_t();
}

bool NameServer::isLocalManager(std::string& ip, uint16_t port)
{
	bool ret = false;
	if (ip == m_nsLocation.getIpAddress() && port == m_nsLocation.getPort())
	{
		ret = true;
	}
	return ret;
}


std::string NameServer::getName(Location* loc)
{
	std::string ret = "";
	if (nullptr != loc)
	{
		LocationNameMap_t::iterator it = m_locationMap.find(loc);
		if (it != m_locationMap.end())
		{
			ret = it->second;
		}
	}
	return ret;

}


uint32_t NameServer::NameServerProc(void* param)
{
	uint32_t ret = 0;
	bool isMns = NameServer::getNameServer()->checkIfMns();
	if (isMns)
	{
		// Is MNS. Start Server to listen for name server clients
		MnsServer* server = MnsServer::getMnsServer();
		server->startServer();
	}
	else
	{
		// Is Not MNS. Start Client to connect to MNS
	    MnsClient* client = MnsClient::getMnsClient();
		client->startClient();
	}
	return ret;
}



uint16_t NameServer::getLocalPort()
{
	uint16_t ret = INVALID_PORT;

	return ret;
}


std::string NameServer::getLocalIp()
{
	std::string ret = INVALID_IP;


	return ret;

}

void NameServer::Start()
{
	RegisterLocation(&m_nsLocation, &m_nsMailBox, m_nsLocation.getName());

}

bool NameServer::Run()
{
	return false;
}

void NameServer::Stop()
{
}
