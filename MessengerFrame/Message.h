#pragma once
#include <string>
#include <typeinfo>
#include <iostream>
#include <map>
#include "MetaLib/JsonCast.h"
#include "MetaLib/CompactCast.h"
#include "MetaLib/XmlCast.h"
#include "Location.h"



enum class Format_t : uint8_t
{
	JSON,
	COMPACT, // Message is compacted in way defined by Message deserializer/serializer
			 // and has predefined header (TODO)
	XML,
	INVALID
};


class Message
{
public:


	Message(Format_t format = Format_t::XML);
	virtual ~Message();

	inline void setName(const std::string& name)
	{
		
		m_name = name;
		
	}

	inline const std::string& getName() const
	{
		
		return m_name;
	}

	inline Format_t getFormat()
	{
		return m_format;
	}



	void setDest(const Location& loc);

	const Location& getDest() const;

	void setSrc(const Location& loc);

	const Location& getSrc() const;





	inline uint64_t getUid() const
	{
		return m_uid;
	}
	inline void setUid(uint64_t uid)
	{
		m_uid = uid;
	}

	virtual Message* deserialize(json& jmsg);

	virtual Message* deserialize(rapidxml::xml_document<>* doc);

	virtual Message* deserialize(std::vector<uint8_t>& byteStream);

protected:


	


private:
	// Used to identify this class of messages
	std::string m_name;
	// Used to uniquely identify individual message.
	uint64_t m_uid;
	// Used to denote which of the different schemas 
	Format_t m_format;

    
	std::string m_srcName;
	uint16_t m_srcPort;
	std::string m_srcAddr;

	std::string m_destName;
	uint16_t m_destPort;
	std::string m_destAddr;


};
namespace meta
{


	template <>
	inline auto registerMembers<Message>()
	{
		return members(
			member("NAME", &Message::getName, &Message::setName), // access through getter/setter only!
			member("m_uid", &Message::getUid, &Message::setUid), // same, but ref getter/setter
			//member("m_src", &Message::m_src),
			//member("m_dest", &Message::m_dest)
			member("m_dest", &Message::getDest, &Message::setDest),
			member("m_src", &Message::getSrc, &Message::setSrc)
			

		//	member("fff", &Message::m_fff)
		);
	}


}

template <typename Derived>
class MessageCRTP : public Message
{
public:
	
	MessageCRTP(Format_t format = Format_t::JSON) :
		Message(format)
	{}

	virtual Message* deserialize(json& jmsg) override
	{
		Derived* derv = dynamic_cast<Derived*>(this);
		meta::deserialize<Derived>(*derv, jmsg);
		return this;
	}
	
	virtual Message* deserialize(rapidxml::xml_document<>* doc) override
	{
		Derived* derv = dynamic_cast<Derived*>(this);
		meta::deserialize_doc<Derived>(*derv, doc);
		return this;
	}
	
	virtual Message* deserialize(std::vector<uint8_t>& byteStream) override
	{
		Derived* derv = dynamic_cast<Derived*>(this);
		meta::deserializeCompact<Derived>(byteStream, *derv);
		return this;
	}

	const Message& getMsg() const
	{
		return *(this);
	}
	void setMsg(const Message& msg)
	{
		// Do nothing
	}

};
#define Derive_Message_CRTP(Type) class Type: public MessageCRTP<Type>




