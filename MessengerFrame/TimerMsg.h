#pragma once
#include "Message.h"
#include <Timer.h>
Derive_Message_CRTP(TimerMsg)
{
public:
	TimerMsg(bool isPeriodic, uint64_t period);
	TimerMsg() {}
	~TimerMsg(void);

	inline Timer* getTimer(void)
	{
		return m_timer;
	}
	inline void setTimer(Timer* timer)
	{
		m_timer = timer;
	}
	bool m_isPeriodic;
	uint64_t m_period;
private:
	Timer* m_timer;

};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<TimerMsg>()
	{
		return members(
			member("MESSAGE", &TimerMsg::getMsg, &TimerMsg::setMsg),
			member("m_isPeriodic", &TimerMsg::m_isPeriodic),
			member("m_period", &TimerMsg::m_period)
		);
	}

}