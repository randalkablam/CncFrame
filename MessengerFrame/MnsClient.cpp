#include "MnsClient.h"
#include "SysEnv.h"
#include "Marshaller.h"


MnsClient* MnsClient::ms_mnsClientPtr = nullptr;


MnsClient* MnsClient::getMnsClient(void)
{
	MnsClient *ret = ms_mnsClientPtr;

	if (nullptr == ms_mnsClientPtr)
	{
		ms_mnsClientPtr = new MnsClient();
		ret = ms_mnsClientPtr;
	}

	return ret;
}

MnsClient::~MnsClient()
{
}

bool MnsClient::onReceive()
{

	bool ret = false;
	// Read in all data and then deserialize the message and send to the appropriate manager
	// If the manager location deserialized does not exist, route an error.
	std::vector<uint8_t> recvBuf;
	uint16_t index = 0;

	uint32_t recvSize = 0;
	while (1)
	{
		int32_t len = recvData(recvBuf, index, getSocketDesciptor(), DEFAULT_CHUNK_SIZE);
		if (len < 0)
		{
			// Route error!!!

			ret = false;
			break;
		}
		else if (len <= DEFAULT_CHUNK_SIZE)
		{
			index += len;
			recvSize += len;
		}
		else // len == 0
		{
			Marshaller* marshallPtr = Marshaller::getMarshaller();
			if (nullptr != marshallPtr)
			{
				Format_t format = static_cast<Format_t>(recvBuf.front());
				if (format >= Format_t::INVALID)
				{
					Location* loc = marshallPtr->extractLocation(recvBuf, format);
					if (nullptr != loc)
					{
						Message* msg = marshallPtr->extractMessage(recvBuf, format);

						if (nullptr != msg)
						{

							loc->enqueueItem(msg);
						}
						else
						{
							// TODO cleanup, error reporting... 
							delete loc;

						}
					}
					else
					{
						// TODO cleanup, error reporting... 
					}
				}
				else
				{
					// TODO cleanup, error reporting... 
				}
			}

		}

	}
	return true; //TODO
}

bool MnsClient::onConnect()
{
	return false;
}

bool MnsClient::onDisconnect()
{
	return false;
}

MnsClient::MnsClient() :
	IpClient(SYS_ENV::MNS_IP, SYS_ENV::MNS_PORT)
{

}