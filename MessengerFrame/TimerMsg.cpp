#include "TimerMsg.h"

TimerMsg::TimerMsg(bool isPeriodic, uint64_t period) :
	m_timer(new Timer(isPeriodic, period))
{

}

TimerMsg::~TimerMsg(void)
{
	if (nullptr != m_timer)
	{
		delete m_timer;
	}
}
