#include <ThreadManager.h>
#include "HighLevelGui.h"
#include "Boot/ManagerBooter.h"
int main(int argc, char *argv[])
{

	ManagerBooter* mgrBooter = ManagerBooter::getManagerBooter();
	HighLevelGui* hlg = HighLevelGui::getMgr();

	mgrBooter->registerManager(hlg);
	mgrBooter->bootManagers();

	ThreadManager::getThreadManager()->waitOnThreads();
	return 0;
}
