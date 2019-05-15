#pragma once
#include <string>
class Location
{
public:
	typedef enum {
		NOT_CONNECTED,
		PENDING,
		CONNECTED,
		UNKNOWN

	} ConnStatus_t;

	const std::string INVALID_IP = "";
	static const uint16_t INVALID_PORT = 0;
	Location();
	Location(const std::string &ip, const uint16_t port);
	~Location();
	std::string getIpAddress();
	uint16_t getPort();
	ConnStatus_t getConnStatus();

private:


	bool checkIpAddress(const std::string &ip, const uint16_t port);
	uint16_t getLocalPort();
	std::string getLocalIp();
	
	
	std::string m_ipAddress;
	uint16_t m_port;




};

