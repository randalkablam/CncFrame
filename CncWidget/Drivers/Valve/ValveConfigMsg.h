#pragma once
#include "Message.h"
#include "Valve.h"
Derive_Message_CRTP(ValveConfigMsg)
{
public:
	ValveConfigMsg();
	~ValveConfigMsg(void);

	std::vector<Valve> m_valveVec;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<ValveConfigMsg>()
	{
		return members(
			member("m_valveVec", &ValveConfigMsg::m_valveVec)

		);
	}

}