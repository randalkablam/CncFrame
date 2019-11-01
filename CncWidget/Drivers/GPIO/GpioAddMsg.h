#pragma once
#include <Message.h>

// This class will put the gpio pin on the read list
Derive_Message_CRTP(GpioAddMsg)
{
public:
	GpioAddMsg();
	

	uint8_t m_pin;


};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<GpioAddMsg>()
	{
		return members(
			member("m_pin", &GpioAddMsg::m_pin)
		);
	}

}