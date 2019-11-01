#pragma once
#include "Message.h"



class DataItem : public Message
{
public:
	DataItem();
	~DataItem();
	uint32_t getUid();
	
private:

};

