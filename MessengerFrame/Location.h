#pragma once
#include <string>
#include <queue>
#include <mutex>

class Message;

class Location
{
public:
	typedef enum {
		NOT_CONNECTED,
		PENDING,
		CONNECTED,
		UNKNOWN

	} ConnStatus_t;

	Location() :
		m_ipAddress(""),
		m_port(0),
		m_mgrName("")
	{}
	Location(const std::string& managerName);
	//Location(Location& loc)
	//{
	//	setIpAddress(loc.getIpAddress());
	//	setPort(loc.getPort());
	//	setName(loc.getName());
	//}

	//Location& operator = (const Location& loc)
	//{
		//m_ipAddress = loc.getIpAddress();
		//m_mgrName = loc.getName();
		//m_port = loc.getPort();
		//return *this;
	//}
	Location(const std::string& ip, uint16_t port, const std::string &mgrName);
	~Location();
	const std::string & getIpAddress() const;
	uint16_t getPort() const;
	const std::string & getName() const;




	void setIpAddress(const std::string& ip);
	void setPort(uint16_t port);
	void setName(const std::string& name);

	ConnStatus_t getConnStatus();

	// Will forward message to location if it is in same process or the name server will take it off of the shared 
	// queue and then forward it over TCP/IP to the other name server on the other process and then that will pass it off
	// to the real manager
	bool enqueueItem(Message* msg);
	Message* dequeueItem(bool& status);

private:


	bool checkIpAddress(const std::string &ip, const uint16_t port);

	
	
	std::string m_ipAddress;
	uint16_t m_port;
	uint64_t m_uid; // uid unique only to process location is associated with






	friend bool operator == (const Location& rhs, const Location& lhs);

	std::string m_mgrName;
};

class LocationMailBox
{
public:
	
	typedef std::queue<Message*> MsgQueue_t;

	MsgQueue_t m_msgQueue;

    std::mutex m_msgQueueMutex;

};


#include <MetaLib/Meta.h>
namespace meta
{
	template <>
	inline auto registerMembers<Location>()
	{
		return members(
			member("m_mgrName", &Location::getName, &Location::setName), // access through getter/setter only!
			member("m_ipAddress", &Location::getIpAddress, &Location::setIpAddress), // same, but ref getter/setter
			member("m_port", &Location::getPort, &Location::setPort)//,
			//member("m_msgQueue", &Location::getMsgQueue, &Location::setMsgQueue),
		//	member("m_msgMutex", &Location::getMsgMutex, &Location::setMsgMutex)



		);
	}
}