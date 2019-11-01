#include "Message.h"
#include "NameServer.h"

Message::Message(Format_t format) :
	m_name(typeid(*this).name()),
	m_uid(0),
	m_format(format)
{	
	Location *loc = NameServer::getNameServer()->getLocation("NameServer");
	std::string name = "";
	std::string addr = NameServer::INVALID_IP;
	uint16_t port = NameServer::INVALID_PORT;

	if (nullptr != loc)
	{
		name = loc->getName();
		addr = loc->getIpAddress();
		port = loc->getPort();
		setSrc(*loc);
		setDest(*loc);
	}
	else
	{
		Location temp;
		setSrc(temp);
		setDest(temp);
	}
	
	//addVariableName("SRC_NAME", m_srcName);
	//addVariableName("SRC_IPADDR", m_srcAddr);
	//addVariableName("SRC_PORT", m_srcPort);

}


Message::~Message()
{
}

const Location& Message::getSrc() const
{
	return *(NameServer::getNameServer()->getLocation(m_srcName));
}



const Location& Message::getDest() const
{
	return *(NameServer::getNameServer()->getLocation(m_destName));
}

void Message::setSrc(const Location& loc)
{


	m_srcName = loc.getName();
	m_srcAddr = loc.getIpAddress();
	m_srcPort = loc.getPort();

}
void Message::setDest(const Location& loc)
{


	m_destName = loc.getName();
	m_destAddr = loc.getIpAddress();
	m_destPort = loc.getPort();

}

Message* Message::deserialize(json& jmsg)
{
	meta::deserialize<Message>(*this, jmsg);
	return this;
}
Message* Message::deserialize(rapidxml::xml_document<>* doc)
{
	meta::deserialize_doc<Message>(*this, doc);
	return this;
}
Message* Message::deserialize(std::vector<uint8_t>& byteStream)
{
	meta::deserializeCompact<Message>(byteStream, *this);
	return this;
}