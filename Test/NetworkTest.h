#pragma once
#include "IpClient.h"
#include "IpServer.h"

#include "NetworkManager.h"


class NetworkTest
{
public:

	bool runTest();

	class ServerExample : public IpServer
	{
	public:
		ServerExample() :
			IpServer("127.0.0.1", 5555)
		{
			NetworkManager* netMgr = NetworkManager::getNetworkManager();

			netMgr->RegisterServer(this);
		}
		virtual bool onReceive(Connection_t& conn)
		{
			std::vector<uint8_t> recvBuf;
			recvData(recvBuf, getSocketDesciptor());
			std::string msgStr(reinterpret_cast<char*>(&recvBuf[0]));

			if (msgStr != "\n" && msgStr != "")
			{
				std::cout << recvBuf[0] << std::endl;
			}
			return true;
		
		}
		virtual bool onConnect(Connection_t& conn)
		{


			sendData("Hello World\n\0", conn.sd);


			return true;
		}
		virtual bool onDisconnect(Connection_t& conn)
		{
			return true;
		}
		virtual std::string getHeartBeatMsg()
		{
			return "\n";
		
		}

	};

	class ClientExample : public IpClient
	{
	public:
		ClientExample() :
			IpClient("127.0.0.1", 5555)
		{
			NetworkManager* netMgr = NetworkManager::getNetworkManager();

			netMgr->RegisterClient(this);

		}

		virtual bool onReceive()
		{
			std::vector<uint8_t> recvBuf;
			recvData(recvBuf, getSocketDesciptor());
			std::string msgStr(reinterpret_cast<char*>(&recvBuf[0]));

			if (msgStr != "\n" && msgStr != "")
			{
				std::cout << &recvBuf[0] << std::endl;
			}
			return true;
		}
		virtual bool onConnect()
		{
			return true;
		}
		virtual bool onDisconnect()
		{
			return true;
		}
		virtual std::string getHeartBeatMsg()
		{
			return "\n";

		}
	};

};

