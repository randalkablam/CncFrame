#pragma once
#include <Manager.h>

// This manager will provide data for files, allowing for transfer of files from
// different machines from the requester
class FileManager : public Manager
{
public:


	// Manager Methods
	static FileManager* getMgr();

	static bool writeFile(const std::string& filename, const std::vector<uint8_t>& data);

	uint32_t getFileRequest(Message& msg);



protected:
	virtual void Start();
	virtual bool Run();
	virtual void Stop();

private:
	FileManager();
	~FileManager();

	static FileManager* ms_fileManagerPtr;


};

