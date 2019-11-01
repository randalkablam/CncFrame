#include "MnsServer.h"
#include "SysEnv.h"
#include "Marshaller.h"

MnsServer* MnsServer::ms_mnsServerPtr = nullptr;


MnsServer* MnsServer::getMnsServer(void)
{
	MnsServer* ret = ms_mnsServerPtr;

	if (nullptr == ms_mnsServerPtr)
	{
		ms_mnsServerPtr = new MnsServer();
	}

	return ret;
}

MnsServer::MnsServer() :
	IpServer(SYS_ENV::MNS_IP, SYS_ENV::MNS_PORT)
{
}

MnsServer::~MnsServer()
{
}

bool MnsServer::onReceive(Connection_t& conn)
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
					Message* msg = marshallPtr->extractMessage(recvBuf, format);
					loc->enqueueItem(msg);
				}
				else
				{
					// TODO cleanup, error reporting... 
				}
			}

		}

	}
	return true;
}


bool MnsServer::onConnect(Connection_t& conn)
{
	return false;
}

bool MnsServer::onDisconnect(Connection_t& conn)
{
	return false;
}
