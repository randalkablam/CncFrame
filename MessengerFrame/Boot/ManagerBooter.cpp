#include "ManagerBooter.h"
#include "..//Manager.h"
ManagerBooter* ManagerBooter::ms_managerBooter = nullptr;

ManagerBooter* ManagerBooter::getManagerBooter()
{
	if (nullptr == ms_managerBooter)
	{
		ms_managerBooter = new ManagerBooter();

	}
	return ms_managerBooter;
}

bool ManagerBooter::registerManager(Manager* mgr)
{

	bool ret = false;
	
	if (nullptr != mgr)
	{
		auto it = m_mgrVec.begin();
		auto endIt = m_mgrVec.end();

		bool found = false;

		// Check whether the manager is already in the vector
		while (it != endIt)
		{
			if ((it)->first == mgr)
			{
				found = true;
				ret = false;
			}

			++it;
		}

		// If the manager was not found add it to the vector...
		if (!found)
		{
			m_mgrVec.insert(std::pair<Manager*, bool>(mgr, false));

		}
	}
	return ret;
}

int32_t ManagerBooter::bootManagers()
{
	// Default is to return -1 indicating an error in booting managers
	// Will ortherwise return number of managers booted
	int32_t ret = -1;

	auto it = m_mgrVec.begin();
	auto endIt = m_mgrVec.end();

	while (it != endIt)
	{
		Manager* mgr = (it)->first;
		if (nullptr != mgr)
		{

			mgr->StartManager();
			it->second = true;


		}

		++it;
	}



	return ret;
}

void ManagerBooter::addManager(std::string &name, ManagerGetter_t *getter)
{
	m_getterMap[name] = getter;
}

ManagerBooter::ManagerBooter()
{
}
