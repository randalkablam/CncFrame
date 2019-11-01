#pragma once
#include "Message.h"
#include "Pump.h"
Derive_Message_CRTP(PumpConfigMsg)
{
public:
	PumpConfigMsg();
	~PumpConfigMsg(void);

	std::vector<Pump> m_pumpVec;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<PumpConfigMsg>()
	{
		return members(
			member("m_pumpVec", &PumpConfigMsg::m_pumpVec)

		);
	}

}