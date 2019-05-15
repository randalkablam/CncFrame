#include "Location.h"


Location::Location()
{
	m_port = getLocalPort();
	m_ipAddress = getLocalIp();

}

Location::Location(const std::string& ip, const uint16_t port) :
	m_ipAddress(ip),
	m_port(port)
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
		m_ipAddress = INVALID_IP;
		m_port = INVALID_PORT;

	}
}



Location::~Location()
{
}


std::string Location::getIpAddress()
{
	return m_ipAddress;


}


uint16_t Location::getPort()
{
	return m_port;

}


Location::ConnStatus_t Location::getConnStatus()
{
	ConnStatus_t ret = ConnStatus_t::UNKNOWN;




	return ret;

}


bool Location::checkIpAddress(const std::string& ip, const uint16_t port)
{
	bool ret = false;

	


	return ret;


}

uint16_t Location::getLocalPort()
{
	uint16_t ret = INVALID_PORT;

	return ret;
}


std::string Location::getLocalIp()
{
	std::string ret = INVALID_IP;


	return ret;

}