#pragma once
#include <vector>
#include <map>
#include <string>
class Manager;

class ManagerBooter
{
public:
	typedef Manager* ManagerGetter_t();

	static ManagerBooter* getManagerBooter();

	
	bool registerManager(Manager* mgr);

	int32_t bootManagers();

	void addManager(std::string &name, ManagerGetter_t *getter);


private:
	ManagerBooter();

	static ManagerBooter* ms_managerBooter;

	// Map of managers and whether they have already been booted.
	typedef std::map<Manager*, bool> ManagerVec_t;

	ManagerVec_t m_mgrVec;


	typedef std::map<std::string, ManagerGetter_t*> GetterMap_t;
	GetterMap_t m_getterMap;

};