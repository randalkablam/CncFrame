#pragma once
#include <Message.h>

// This class will be sent to location with the value of a specified gpio pin
Derive_Message_CRTP(GpioValueMsg)
{
public:
	GpioValueMsg(void);
	

	uint16_t m_pin;
	bool m_value;

};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<GpioValueMsg>()
	{
		return members(
			member("m_pin", &GpioValueMsg::m_pin),
			member("m_value", &GpioValueMsg::m_value)
		);
	}

}