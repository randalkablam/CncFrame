#pragma once
#include "Message.h"

Derive_Message_CRTP(NameServerInterchangeMsg)
{

public:

	NameServerInterchangeMsg() {}

	std::vector<Location> m_managers;


};


#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<NameServerInterchangeMsg>()
	{
		return members(
			member("MESSAGE", &NameServerInterchangeMsg::getMsg, &NameServerInterchangeMsg::setMsg),
			member("m_managers", &NameServerInterchangeMsg::m_managers)
		);
	}

}