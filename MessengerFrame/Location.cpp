#include "Location.h"
#include "Message.h"
#include "NameServer.h"

Location::Location(const std::string& managerName):
	m_ipAddress(""),
	m_port(0),
	m_mgrName(""),
	m_uid(0)
{
	NameServer* ns = NameServer::getNameServer();
	m_port = ns->getLocalPort();
	m_ipAddress = ns->getLocalIp();
	m_mgrName = managerName;
}

Location::Location(const std::string& ip, uint16_t port, const std::string& mgrName) :
	m_ipAddress(ip),
	m_port(port),
	m_mgrName(mgrName)
{
	// Check whether ip/port combo is valid for the processor being used
	// i.e. Is the port already in use and is there an interface for the given
	// ip address
	bool addrOk = checkIpAddress(ip, port);
	if (addrOk)
	{
		// Provided address matches a system address
		m_ipAddress = ip;
		m_port = port;
	}
	else
	{
		// Provided address is invalid and cannot be connected to/used
		m_ipAddress = NameServer::INVALID_IP;
		m_port = NameServer::INVALID_PORT;

	}
	static uint64_t uid = 0;

	m_uid = uid++;
}



Location::~Location()
{
}


const std::string& Location::getIpAddress() const
{
	return m_ipAddress;


}


uint16_t Location::getPort() const
{
	return m_port;

}

const std::string& Location::getName() const
{
	return m_mgrName;
}


void Location::setIpAddress(const std::string& ip)
{
	// do nothing
}

void Location::setPort(uint16_t port)
{
	// do nothing
}

void Location::setName(const std::string& name)
{
	// do nothing
}

Location::ConnStatus_t Location::getConnStatus()
{
	ConnStatus_t ret = ConnStatus_t::UNKNOWN;




	return ret;

}

bool Location::enqueueItem(Message* msg)
{
	bool ret = false;

	NameServer* ns = NameServer::getNameServer();
	LocationMailBox *box = ns->getMailBox(this);
	if (nullptr != box)
	{
		std::unique_lock<std::mutex> lock(box->m_msgQueueMutex);
		try
		{
			if (nullptr != msg)
			{
				box->m_msgQueue.push(msg);
				ret = true;
			}
		}
		catch (...)
		{
			ret = false;

		}
	}
	return ret;
}

Message* Location::dequeueItem(bool& status)
{
	// TODO: insert return statement here
	Message* ret = nullptr;
	NameServer* ns = NameServer::getNameServer();
	LocationMailBox* box = ns->getMailBox(this);
	if (nullptr != box)
	{
		std::unique_lock<std::mutex> lock(box->m_msgQueueMutex);


		try
		{
			if (box->m_msgQueue.empty())
			{
				status = false;
			}
			else
			{

				ret = box->m_msgQueue.front();
				box->m_msgQueue.pop();


			}

			

		}
		catch (...)
		{
			// TODO route error
			status = false;
		}
	}
	return ret;
}


bool Location::checkIpAddress(const std::string& ip, const uint16_t port)
{
	bool ret = true;




	return ret;


}

bool operator == (const Location& rhs, const Location& lhs)
{
	bool ret = true;

	ret |= (rhs.getIpAddress() == lhs.getIpAddress());
	ret |= (rhs.getName() == lhs.getName());
	ret |= (rhs.getPort() == lhs.getPort());

	return ret;

}
