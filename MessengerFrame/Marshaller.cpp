#include "Marshaller.h"
#include "MetaLib/rapidxml_ext.h"
#include "MetaLib/rapidxml_utils.hpp"
#include <sstream>
#include <iterator>
#include "NameServer.h"


using nlohmann::json;


Marshaller* Marshaller::m_marshallerPtr = nullptr;

Marshaller* Marshaller::getMarshaller()
{
	if (nullptr == m_marshallerPtr)
	{
		m_marshallerPtr = new Marshaller();
	}

	return m_marshallerPtr;
}

Location* Marshaller::extractLocation(std::vector<uint8_t>& byteStream, Format_t format)
{
	Location* ret = nullptr;
	switch (format)
	{
	case Format_t::JSON:
		ret = extractLocationJson(byteStream);
		break;
	case Format_t::COMPACT:
		ret = extractLocationCompact(byteStream);
		break;
	case Format_t::XML:
		ret = extractLocationXml(byteStream);
		break;

	default:
		ret = nullptr;
	}
	return ret;
}

Message* Marshaller::extractMessage(std::vector<uint8_t>& byteStream, Format_t format)
{

	Message* ret = nullptr;
	switch (format)
	{
	case Format_t::JSON:
		ret = extractMessageJson(byteStream);
		break;
	case Format_t::COMPACT:
		ret = extractMessageCompact(byteStream);
		break;
	case Format_t::XML:
		ret = extractMessageXml(byteStream);
		break;

	default:
		ret = nullptr;
	}
	return ret;

}




Marshaller::Marshaller() :
	m_msgNames()
{
}


Marshaller::~Marshaller()
{
}

Location* Marshaller::extractLocationJson(std::vector<uint8_t>& byteStream)
{

	Location* ret = nullptr;
	json* jsonObj = extractJsonObj(byteStream);
	if (nullptr != jsonObj)
	{
		std::string locIpKey = "DEST_IP";
		std::string ip;
		getElemFromJson<std::string>(*jsonObj, locIpKey, ip);


		std::string locPortKey = "DEST_PORT";
		uint16_t port;
		getElemFromJson<uint16_t>(*jsonObj, locPortKey, port);


		std::string locNameKey = "DEST_NAME";
		std::string mgrName;
		getElemFromJson<std::string>(*jsonObj, locNameKey, mgrName);

		NameServer* ns = NameServer::getNameServer();

		if (ns->isLocalManager(ip, port))
		{
			ret = ns->getLocation(mgrName);
		}

		delete jsonObj;
	}


	return ret;
}

Message* Marshaller::extractMessageJson(std::vector<uint8_t>& byteStream)
{
	Message* ret = nullptr;
	json* jsonObj = extractJsonObj(byteStream);
	if (nullptr != jsonObj)
	{
		std::string nameKey = "MESSAGE";
		std::string name = (*jsonObj)[nameKey]["NAME"];

		ret = getMessageObjFromName(name);
		if (nullptr != ret)
		{
			 ret->deserialize(*jsonObj);


			//importVariableNamesJson(*ret, *jsonObj);
		}
		delete jsonObj;
	}
	return ret;
}

Location* Marshaller::extractLocationCompact(std::vector<uint8_t>& byteStream)
{
	Location* ret = nullptr;

	uint32_t index = 0;

	// Get message name and discard/ignore for now
	std::string msgName(reinterpret_cast<char*>(&byteStream[index]));
	index += msgName.length() + 1;


	// Get Ip Address
	std::string ip(reinterpret_cast<char*>(&byteStream[index]));
	index += ip.length() + 1;

	// Get Port
	uint16_t port = ((uint16_t)byteStream[index + 0] << 8) | ((uint16_t)byteStream[index + 1]);
	index += 2;

	// Get Manager Name
	std::string mgrName(reinterpret_cast<char*>(&byteStream[index + 0]));
	index += mgrName.length() + 1;

	NameServer* ns = NameServer::getNameServer();

	if (ns->isLocalManager(ip, port))
	{
		ret = ns->getLocation(mgrName);
	}

	return ret;
}

Message* Marshaller::extractMessageCompact(std::vector<uint8_t>& byteStream)
{
	Message* ret = nullptr;



	std::string name;
	uint32_t index = 0;
	//extractFromByteStream<std::string>(byteStream, index, name);


	// Get destination info and discard
	// Get Ip Address
	std::string ip(reinterpret_cast<char*>(&byteStream[index]));
	index += ip.length() + 1;

	// Get Port
	uint16_t port = ((uint16_t)byteStream[index + 0] << 8) | ((uint16_t)byteStream[index + 1]);
	index += 2;

	// Get Manager Name
	std::string mgrName(reinterpret_cast<char*>(&byteStream[index + 0]));
	index += mgrName.length() + 1;


	ret = getMessageObjFromName(name);
	if (ret != nullptr)
	{
		//importVariableNamesCompact(*ret, byteStream, index);
	}
	return ret;

}

Location* Marshaller::extractLocationXml(std::vector<uint8_t>& byteStream)
{
	Location* ret = nullptr;
	rapidxml::xml_document<>* doc = new rapidxml::xml_document<>();


	doc->parse<0>((char*)(&byteStream[0]));

	rapidxml::xml_node<>* root_node;
	root_node = doc->first_node("page");
	if (nullptr != root_node)
	{
		std::string ip = root_node->first_attribute("DEST_IP")->value();
		uint16_t port = std::stol(root_node->first_attribute("DEST_PORT")->value());
		std::string mgrName = root_node->first_attribute("DEST_NAME")->value();

		NameServer* ns = NameServer::getNameServer();

		if (ns->isLocalManager(ip, port))
		{
			ret = ns->getLocation(mgrName);
		}
	}

	return ret;
}

Message* Marshaller::extractMessageXml(std::vector<uint8_t>& byteStream)
{
	Message* ret = nullptr;
	rapidxml::xml_document<>* doc = new rapidxml::xml_document<>();


	doc->parse<0>((char*)(&byteStream[0]));


	rapidxml::xml_node<>* root_node;
	root_node = doc->first_node("message");
	if (nullptr != root_node)
	{
		if (nullptr != root_node->first_node("MESSAGE"))
		{
			if (nullptr != root_node->first_node("MESSAGE")->first_node("NAME"))
			{
				std::string name(root_node->first_node("MESSAGE")->first_node("NAME")->value());
				ret = getMessageObjFromName(name);
				if (nullptr != ret)
				{
					//importVariableNamesXml(*ret, *doc);
					ret->deserialize(doc);
				}
			}
		}
	}

	return ret;
}



json* Marshaller::extractJsonObj(std::vector<std::uint8_t>& str)
{


	// Default return null
	json* ret = nullptr;

	try
	{
		ret = new json(json::parse(str));


	}
	catch (json::parse_error& e)
	{
		// Will return null

		// TODO route error
	}

	return ret;


}



Message* Marshaller::getMessageObjFromName(std::string& name)
{
	Message* ret = nullptr;

	try {
		std::map<std::string, NewMessage_t*>::iterator it;
		it = m_msgNames.find(name);
		if (it != m_msgNames.end())
		{
			ret = (*(it->second))();
		}
	}
	catch (...)
	{

		// TODO error handling...
	}
	return ret;
}


