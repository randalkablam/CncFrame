#include "Slot.h"
#include "Manager.h"

Slot::Slot(Manager* mgr) :
	m_mgr(mgr),
	m_slotFunc(std::bind(&Slot::defaultHandler, this, std::placeholders::_1))
{

}

bool Slot::connectSignal(Message& msg)
{
	std::vector<Message>::iterator it = m_acceptedSignals.begin();
	std::vector<Message>::iterator endIt = m_acceptedSignals.end();
	bool alreadyIn = false;
	while (it != endIt)
	{
		if ((*it).getName() == msg.getName())
		{
			alreadyIn = true;
			break;
		}
	}
	if (!alreadyIn)
	{
		// TODO extend to perform any possible mutexin that might be needed if this class becomes more complicated...
		m_acceptedSignals.push_back(msg);
	}
	return true;
}

bool Slot::registerSlot(SlotFunc_t slotFunc)
{
	m_slotFunc = slotFunc; 

	return true;
}

uint32_t Slot::operator()(Message& msg)
{
	uint32_t ret = m_slotFunc(msg);

	return ret;
}

uint32_t Slot::defaultHandler(Message&)
{
	return 0;
}
