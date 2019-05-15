#pragma once
#include <string>
#include <map>
#include "Location.h"
#include "DataItem.h"

class NameServer
{
public:


	static NameServer* getNameServer();

	bool RegisterLocation(Location& loc, const std::string managerName);
	bool RegisterObject(DataItem& d);


	Location getLocation(const std::string& name);
	std::string getName(const Location& loc);


private:

	static NameServer* m_nameServerPtr;

	NameServer();
	~NameServer();

	bool checkIfMns();


	typedef std::map<std::string, Location> LocationNameMap_t;
	
	// Used to map an id to a shared DataItem
	// Can be marshalled sent to managers requesting a data item with a specific id.
	// 
	typedef std::map<uint16_t, DataItem*> DataItemMap_t;

	LocationNameMap_t m_locationMap;
	DataItemMap_t m_dataMap;


	bool m_isMNS;
	Location m_nsLocation;


	static uint32_t NameServerProc(void* param);

};

