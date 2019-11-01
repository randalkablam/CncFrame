#include "GpioManager.h"
#include "GpioAddMsg.h"
#include "GpioLockReply.h"
#include "GpioLockRequest.h"
#include "GpioRemoveMsg.h"
#include "GpioValueMsg.h"

#include <NameServer.h>
#include "Utils/PnpDefs.h"


GpioManager* GpioManager::ms_gpioManagerPtr = GpioManager::getMgr();

GpioManager* GpioManager::getMgr()
{
	if (nullptr == ms_gpioManagerPtr)
	{
		ms_gpioManagerPtr = new GpioManager();
	}

	return ms_gpioManagerPtr;
}

bool GpioManager::addGpioListener(uint16_t pin, Location& loc)
{
	bool ret = false;
	try
	{
		GpioLocationMap_t::iterator it = m_gpioLocationMap.find(pin);
		if (m_gpioLocationMap.end() != it)
		{
			LocationVec_t& locVec = (*it).second;
			if (!inLocationVector(loc, locVec))
			{
				locVec.push_back(loc);

			}
			bool ret = true;
		}
		else
		{
			// No vector for this pin yet, add it
			m_gpioLocationMap[pin] = LocationVec_t();
			m_gpioLocationMap[pin].push_back(loc);
		}
		createDriver(pin, true);
	}
	catch (...)
	{
		// TODO error processing

	}
	return ret;
}

bool GpioManager::removeGpioListener(uint16_t pin, Location& loc)
{
	try
	{
		GpioLocationMap_t::iterator it = m_gpioLocationMap.find(pin);
		if (m_gpioLocationMap.end() != it)
		{

			// Loop through locVec and remove any entries equal to loc
			LocationVec_t& locVec = (*it).second;
			LocationVec_t::iterator locIt = locVec.begin();
			LocationVec_t::iterator locEndIt = locVec.end();

			while (locIt != locEndIt)
			{
				// Erase vector entry if it contains the location
				if ((*locIt) == loc)
				{
					locVec.erase(locIt);
				}
				else
				{
					++locIt;
				}
			}
			// Remove loc vector from map if it is empty now...
			if (locVec.empty())
			{
				m_gpioLocationMap.erase(it);

				// Delete pin from pin descriptor map
				GpioPinMap_t::iterator pinIt = m_pinDriverMap.find(pin);
				uint16_t pd = 0;
				if (m_pinDriverMap.end() != pinIt)
				{
					pd = (*pinIt).second->getHandle();
					m_pinDriverMap.erase(pinIt);
				}
				// Clear file descriptor from set we listen on
				if (0 != pd)
				{
					FD_CLR(pd, &m_pinDescipSet);
				}
			}
		}



	}
	catch (...)
	{
		// TODO error processing

	}

	return false;
}

uint32_t GpioManager::gpioAddMsgSlot(Message& msg)
{
	uint32_t ret = -1;

	GpioAddMsg& addMsg = dynamic_cast<GpioAddMsg&>(msg);
	Location srcLoc = msg.getSrc();

	addGpioListener(addMsg.m_pin, srcLoc);
	ret = 0;

	return ret;
}

uint32_t GpioManager::gpioRemoveMsgSlot(Message& msg)
{
	uint32_t ret = -1;

	GpioRemoveMsg& remMsg = dynamic_cast<GpioRemoveMsg&>(msg);

	Location srcLoc = msg.getSrc();

	removeGpioListener(remMsg.m_pin, srcLoc);
	ret = 0;


	return ret;
}

uint32_t GpioManager::gpioLockRequestSlot(Message& msg)
{
	uint32_t ret = -1;
	GpioLockRequest& lockMsg = dynamic_cast<GpioLockRequest&>(msg);
	Location srcLoc = msg.getSrc();

	// Reply always sent so long as the src location is valid
	GpioLockReply* lockReply = new GpioLockReply();
	lockReply->m_pin = lockMsg.m_pin;


	if (lockMsg.m_lock)
	{
		// Lock the specified pin ... other managers cannot use it now for writes
		NameServer* ns = NameServer::getNameServer();
		if (nullptr != ns)
		{
			std::string ip = srcLoc.getIpAddress();
			uint16_t port = srcLoc.getPort();
			if (ns->isLocalManager(ip, port))
			{

				GpioPinMap_t::iterator pinIt = m_pinDriverMap.find(lockMsg.m_pin);
				if (m_pinDriverMap.end() != pinIt)
				{
					lockReply->m_gpioDriverPtr = reinterpret_cast<uint64_t>(&(pinIt->second));
				}
				else
				{
					GpioDriver* driver = createDriver(lockMsg.m_pin, false);
					lockReply->m_gpioDriverPtr = reinterpret_cast<uint64_t>(&driver);
				}


			}
			else
			{
				// Location is not local and we therefore cannot provide a reference to 
				// the GpioDriver associated with pin number
			}

		}
		sendMsg(*lockReply, srcLoc);
	}
	else
	{
		// Unlock the specified pin ... other managers can now request to lock the pin for writing.
		// In order to guarentee that this driver handle can no longer be used, we will delete the driver and create a new one

	}
	ret = 0;


	return ret;
}


GpioManager::GpioManager() :
	Manager(ManagerNames::GPIO_MANAGER_NAME),
	m_pinDescipSet()
{
	FD_ZERO(&m_pinDescipSet);

}

void GpioManager::Start()
{
	createSlots();
}

bool GpioManager::Run()
{
	// Need to select on the fd_set
#ifdef OS_LINUX
	timeval timeOut;
	timeOut.tv_sec = 0;
	timeOut.tv_usec = 10000;

	fd_set readSet(m_pinDescipSet);
	fd_set writeSet;
	fd_set exceptSet;
	FD_ZERO(&writeSet);
	FD_ZERO(&exceptSet);
	int32_t numSelected = select(FD_SETSIZE, &readSet, &writeSet, &exceptSet, &timeOut);
	if (numSelected < 0)
	{
	}
	else if (0 == numSelected)
	{
	}
	else
	{
		int32_t numServiced = 0;

		// A socket can be read on.

		// Loop through each client and service those sockets that have been set in the fd_set
		GpioPinMap_t::iterator pinIt = m_pinDriverMap.begin();
		const GpioPinMap_t::iterator pinEndIt = m_pinDriverMap.end();
		while (pinEndIt != pinIt && numServiced < numSelected)
		{

			uint16_t fd = (*pinIt).second->getHandle();
			if (FD_ISSET(fd, &readSet))
			{
				bool val = (*pinIt).second->getValue();
				GpioLocationMap_t::iterator mapIt = m_gpioLocationMap.find((*pinIt).first);
				if (m_gpioLocationMap.end() != mapIt)
				{
					LocationVec_t::iterator locIt = (*mapIt).second.begin();
					LocationVec_t::iterator locEndIt = (*mapIt).second.end();
					while (locIt != locEndIt)
					{
						Location loc = (*locIt);


						GpioValueMsg* valMsg = new GpioValueMsg();
						valMsg->m_pin = (*pinIt).first;
						valMsg->m_value = val;
						loc.enqueueItem(valMsg);



						++locIt;
					}
				}

				numServiced++;
			}

			++pinIt;
		}

	}
#endif
	return true;
}

void GpioManager::Stop()
{
}

bool GpioManager::inLocationVector(Location& loc, LocationVec_t& locVec)
{
	bool ret = false;
	LocationVec_t::iterator it = locVec.begin();
	LocationVec_t::iterator endIt = locVec.end();

	while (it != endIt)
	{

		if ((*it) == loc)
		{
			ret = true;
		}
		++it;
	}

	return ret;
}

void GpioManager::createSlots()
{
	{
		Slot* addSl = new Slot(this);
		addSl->registerSlot(std::bind(&GpioManager::gpioAddMsgSlot, this, std::placeholders::_1));
		GpioAddMsg gam;
		addSlot(*addSl, gam);
	}
	{
		Slot* remSl = new Slot(this);
		remSl->registerSlot(std::bind(&GpioManager::gpioRemoveMsgSlot, this, std::placeholders::_1));
		GpioRemoveMsg grm;
		addSlot(*remSl, grm);
	}
	{
		Slot* lockReqSl = new Slot(this);
		lockReqSl->registerSlot(std::bind(&GpioManager::gpioLockRequestSlot, this, std::placeholders::_1));
		GpioLockRequest glreq;
		addSlot(*lockReqSl, glreq);
	}

}

GpioDriver* GpioManager::createDriver(uint16_t pin, bool listen)
{
	// This will create a GpioDriver and set the fd_set if listen is true

	// First check if this pin already has an existing driver
	GpioPinMap_t::iterator pinIt = m_pinDriverMap.find(pin);
	GpioDriver* driver = nullptr;
	if (m_pinDriverMap.end() == pinIt)
	{
		m_pinDriverMap.emplace(std::pair<uint16_t, GpioDriver*>(pin, new GpioDriver(pin)));
		driver = (m_pinDriverMap[pin]);
	}
	else
	{
		driver = ((*pinIt).second);
	}

	// if we are listening on this driver then, set it's file descriptor
	if (listen)
	{
		if (nullptr != driver)
		{
			FD_SET(driver->getHandle(), &m_pinDescipSet);
		}
	}
	return driver;
}


