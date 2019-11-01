#include "IpClient.h"
#include <iostream>


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
	int32_t sd = m_sd;

	if (m_sd < 0)
	{
		sd = createSocket();
	}
	
	if (sd > 0)
	{
		bool configOk = configureSocket(sd);
		if (!configOk)
		{
			//TODO perform error handling
			closeSocket(sd);
			
		}
		else
		{
			setStatus(ClientStatus_t::CONNECTING);
			// Socket created is valid
			ret = connectTo(sd);
			if (true == ret)
			{
				setStatus(ClientStatus_t::CONNECTED);
			}
			else
			{
				//TODO error handling
				std::cout << "client err " << GetLastError() << std::endl;
			}
		}
	}
	else
	{
		setStatus(ClientStatus_t::NOT_CONNECTED);

	}
	return ret;
}

bool IpClient::stopClient()
{
	bool ret = false;
	closeSocket(m_sd); 
	//TODO check if closed successfully
	return ret;

}