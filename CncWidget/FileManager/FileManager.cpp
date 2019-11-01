#include "FileManager.h"
#include "Utils/PnpDefs.h"
#include "FileRequest.h"
#include "FileReply.h"
#include <fstream>

FileManager* FileManager::ms_fileManagerPtr = FileManager::getMgr();

FileManager* FileManager::getMgr()
{
	if (nullptr == ms_fileManagerPtr)
	{
		ms_fileManagerPtr = new FileManager();


	}
	return ms_fileManagerPtr;
}

bool FileManager::writeFile(const std::string& filename, const std::vector<uint8_t>& data)
{
	bool ret = false;
	std::fstream file(filename);
	if (file.is_open())
	{
		file.write(reinterpret_cast<const char*>(&data[0]), data.size());

		file.close();
		ret = true;
	}
	return ret;
}

uint32_t FileManager::getFileRequest(Message& msg)
{
	// Returns number of bytes read
	uint32_t ret = 0;
	Location src = msg.getSrc();
	FileReply* fp = new FileReply();
	
	fp->setDest(src);
	fp->setSrc(m_location);

	fp->setFileName(msg.getName());
	





	return ret;
}

void FileManager::Start()
{
}

bool FileManager::Run()
{
	return false;
}

void FileManager::Stop()
{
}

FileManager::FileManager() : 
	Manager(ManagerNames::FILE_MANAGER_NAME)
{
	Slot* sl = new Slot(this);
	sl->registerSlot(std::bind(&FileManager::getFileRequest, this, std::placeholders::_1));
	FileRequest msg;
	addSlot(*sl, msg);
}

FileManager::~FileManager()
{
}
