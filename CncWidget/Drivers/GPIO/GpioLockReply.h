#pragma once
#include <Message.h>

// Managers (seperate threads) have the ability to obtain direct access to a GpioDriver. 
// Only one manager can write to a GpioDriver at a time, so they need to lock the pin.
// If the manager is not local to the location of GpioManager, then a nullptr value is returned 
Derive_Message_CRTP(GpioLockReply)
{
public:
	GpioLockReply(void);
	uint16_t m_pin;
	uint64_t m_gpioDriverPtr;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<GpioLockReply>()
	{
		return members(
			member("m_pin", &GpioLockReply::m_pin),
			member("m_gpioDriverPtr", &GpioLockReply::m_gpioDriverPtr)
		);
	}

}