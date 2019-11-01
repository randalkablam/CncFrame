#pragma once
#include <string>
#include <vector>
#include "Message.h"

#include <mutex>
#include <functional>

class Manager;

class Slot
{
public:
	// Follow signal slot paradigm of qt and have way of connecting
	// events (message reception for now) to functions that handle those
	// events.
	Slot(Manager* mgr);
	bool connectSignal(Message& msg);
	typedef std::function<uint32_t(Message&)> SlotFunc_t;
	bool registerSlot(SlotFunc_t slotFunc);
	
	uint32_t operator()(Message&);

protected:
	typedef Message Signal_t;
	typedef std::vector<Signal_t> SignalVec_t;
	SignalVec_t m_acceptedSignals;


	Manager* m_mgr;
	SlotFunc_t m_slotFunc;
private:
	uint32_t defaultHandler(Message&);
};

