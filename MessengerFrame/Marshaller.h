#pragma once
#include "OsEnv.h"
#include "Location.h"

#include <vector>

#include "MetaLib/json.hpp"
#include "Message.h"
#include <sstream>
#include <iomanip>
#include "MetaLib/rapidxml_ext.h"

//////////////////////////////////////////////////////////////////////
//
//	Msg Structure (JSON)
//
//
//	
//	Msg Structure (COMPACT)
//  _________________________________________________
//	|0			|8			|16			|24			|32
//  -------------------------------------------------
//  | Mgr Name (Zero terminated) 					|
//  | Msg Name (Zero terminated)					|
//  -------------------------------------------------
//
// Msg Structure (XML)
//
//
//////////////////////////////////////////////////////////////////////

typedef Message* NewMessage_t();


template <typename T>
Message* getNewMessage()
{
	return new T;
}

class Marshaller
{
public:


	static Marshaller* getMarshaller();

	Location* extractLocation(std::vector<uint8_t>& byteStream, Format_t format = Format_t::JSON);

	Message* extractMessage(std::vector<uint8_t>& byteStream, Format_t format = Format_t::JSON);


	template <typename T>
	std::vector<uint8_t>* toByteStream(T& msg)
	{

		std::vector<uint8_t>* ret = new std::vector<uint8_t>();
		switch (msg.getFormat())
		{
		case Format_t::JSON:
			jsonToByteStream(msg, *ret);
			break;
		case Format_t::COMPACT:
			compactToByteStream(msg, *ret);
			break;
		case Format_t::XML:
			xmlToByteStream(msg, *ret);
			break;
		}
		return ret;
	}


	template <typename T>
	void registerMessageName(Message& msg, NewMessage_t* ctor)
	{
		if (m_msgNames.find(msg.getName()) == m_msgNames.end())
		{
			m_msgNames.insert(std::pair<std::string, NewMessage_t*>((msg).getName(), ctor));
		}

	}

private:


	static Marshaller* m_marshallerPtr;
	Marshaller(void);
	~Marshaller(void);

	Location* extractLocationJson(std::vector<uint8_t>& byteStream);
	Message* extractMessageJson(std::vector<uint8_t>& byteStream);

	Location* extractLocationCompact(std::vector<uint8_t>& byteStream);
	Message* extractMessageCompact(std::vector<uint8_t>& byteStream);


	Location* extractLocationXml(std::vector<uint8_t>& byteStream);
	Message* extractMessageXml(std::vector<uint8_t>& byteStream);


	template<typename T>
	void jsonToByteStream(T& msg, std::vector<uint8_t>& ret)
	{

		json jmsg = msg;
		
		std::string dump = jmsg.dump();
		ret.resize(dump.length() + 1);
		std::copy(dump.c_str(), dump.c_str() + dump.length(), ret.begin());
		std::cout << dump << std::endl;
	}

	template<typename T>
	void compactToByteStream(T& msg, std::vector<uint8_t>& ret)
	{
		meta::serialize(msg, ret);
	}

	template<typename T>
	void xmlToByteStream(T& msg, std::vector<uint8_t>& ret)
	{
		rapidxml::xml_document<>* doc = meta::generateXml<T>(msg);
		std::stringstream ss;

		std::ostream_iterator<char> iter(ss);

		rapidxml::print(iter, *doc, rapidxml::print_no_indenting);
		std::string dump = ss.str();
		ret.resize(dump.length() + 1);
		std::copy(dump.c_str(), dump.c_str() + dump.length(), ret.begin());
		doc->clear();
		std::cout << dump << std::endl;
		delete doc;
	}


	Message* getMessageObjFromName(std::string& name);

	nlohmann::json* extractJsonObj(std::vector<std::uint8_t>& str);

	template<typename T>
	void addElemToJson(nlohmann::json& jsonObj, std::string& name, T& val)
	{
		try
		{
			jsonObj.push_back(json::object_t::value_type(name, val));
		}
		catch (nlohmann::json::parse_error& e)
		{
			// TODO Oh no!!! Route error
		}
	}

	
	template<typename T>
	void getElemFromJson(nlohmann::json& jsonObj, const std::string& name, T& val)
	{



		try
		{

			val = (jsonObj).at(name);
			//return T(ret);
		}
		catch (nlohmann::json::parse_error& e)
		{
			// route error

		}


	}


	

	typedef std::map <std::string, NewMessage_t*> MessageNameMap_t;
	MessageNameMap_t m_msgNames;


};


