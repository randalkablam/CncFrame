#pragma once
#include <string>
#include <map>
#include "Location.h"
#include "DataItem.h"
#include "IpClient.h"
#include "IpServer.h"
#include "Manager.h"

// TODO
typedef Message NameServerHeartbeatMsg_t;

class NameServer : public Manager
{
public:

	static const std::string INVALID_IP;
	static const uint16_t INVALID_PORT = 0;

	static NameServer* getNameServer();

	bool RegisterLocation(Location* loc, LocationMailBox* mailBox, const std::string managerName);
	bool RegisterObject(DataItem& d);


	Location* getLocation(const std::string& name);

	uint32_t recvHeartbeat(Message& msg) override;



	bool isLocalManager(std::string& ip, uint16_t port);

	std::string getName(Location* loc);

	uint16_t getLocalPort();
	std::string getLocalIp();


protected:
	virtual void Start() override;
	virtual bool Run() override;
	virtual void Stop() override;
	
private:

	friend Location;

	LocationMailBox* getMailBox(Location* loc);


	static NameServer* m_nameServerPtr;

	NameServer();
	~NameServer();

	bool checkIfMns();
	void registerRemoteDataItem(DataItem& di);


	typedef std::map<std::string, Location*> NameLocationMap_t;
	typedef std::map<Location*, std::string> LocationNameMap_t;

	typedef std::map<Location*, LocationMailBox*> LocationBoxMap_t;

	
	typedef std::map<Location, bool> LocationAlive_t;

	LocationAlive_t m_locationAliveMap;

	// Used to map an id to a shared DataItem
	// Can be marshalled sent to managers requesting a data item with a specific id.
	// 
	typedef std::map<uint16_t, DataItem> DataItemMap_t;

	LocationNameMap_t m_locationMap;
	NameLocationMap_t m_nameMap;

	LocationMailBox m_nsMailBox;

	DataItemMap_t m_dataMap;

	LocationBoxMap_t m_mailBoxMap;
	
	


	bool m_isMNS;
	Location m_nsLocation;


	static uint32_t NameServerProc(void* param);


	

};

