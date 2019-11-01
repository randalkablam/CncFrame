#pragma once
#include <Message.h>
Derive_Message_CRTP(GpioRemoveMsg)
{
public:
	GpioRemoveMsg(void);
	uint16_t m_pin;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<GpioRemoveMsg>()
	{
		return members(
			member("m_pin", &GpioRemoveMsg::m_pin)
		);
	}

}