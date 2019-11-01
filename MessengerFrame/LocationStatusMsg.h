#pragma once
#include "Message.h"

Derive_Message_CRTP(LocationStatusMsg)
{
public:
	LocationStatusMsg() :
		m_health(LocHealth_t::UNKNOWN)
	{}



	enum class LocHealth_t : uint8_t
	{
		UNKNOWN,
		ALIVE,
		DEAD,
		PENDING
	};


	LocHealth_t m_health;

};

