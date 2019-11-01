#pragma once
#include <Message.h>

// Used to request lock for writing (or unlock)
Derive_Message_CRTP(GpioLockRequest)
{
public:
	GpioLockRequest(void);
	bool m_lock;
	uint16_t m_pin;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<GpioLockRequest>()
	{
		return members(
			member("m_pin", &GpioLockRequest::m_pin),
			member("m_lock", &GpioLockRequest::m_lock)
		);
	}

}