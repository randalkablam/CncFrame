#pragma once
#include "Message.h"


Derive_Message_CRTP(HeartbeatMsg) 
{
public:
	HeartbeatMsg() {}
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<HeartbeatMsg>()
	{
		return members(
			member("MESSAGE", &HeartbeatMsg::getMsg, &HeartbeatMsg::setMsg)
		);
	}

}