#include "IpClient.h"



IpClient::IpClient(const std::string &ipAddr, uint16_t port) : 
	IpCore(port, ipAddr)
{
}


IpClient::~IpClient()
{
}

bool IpClient::startClient()
{
	bool ret = false;
	int32_t sd = createSocket();
	if (sd > 0)
	{
		// Socket created is valid
		ret = connectTo(sd);

	}
	return ret;
}

bool IpClient::stopClient()
{
	bool ret = false;
	close(m_sd); 
	//TODO check if closed successfully
	return ret;

}