#pragma once
#include "Message.h"
// This class will hold configuration data
Derive_Message_CRTP(CmdMessage)
{
public:
	CmdMessage();
	CmdMessage(const std::string& cmd);

	std::string m_cmd;

};


#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<CmdMessage>()
	{
		return members(
			member("m_cmd", &CmdMessage::m_cmd)
		);
	}


}

