#pragma once
#include "Message.h"
#include "AxisGeneric.h"
Derive_Message_CRTP(MoveMsg)
{
public:
	MoveMsg();
	~MoveMsg(void);

	AxisName_t m_axisId;
	double m_position; // units from base
	Unit_t m_unitType;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<MoveMsg>()
	{
		return members(
			member("m_axisId", &MoveMsg::m_axisId),
			member("m_position", &MoveMsg::m_position),
			member("m_unitType", &MoveMsg::m_unitType)
		);
	}

}