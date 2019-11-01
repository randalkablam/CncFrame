#include "FileReply.h"
#include <Marshaller.h>


FileReply::FileReply(void) :
	m_filename(""),
	m_rawData(),
	m_sizeRequested(0)
{
	setName("FileReply");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<FileReply>(*this, (NewMessage_t*)& getNewMessage<FileReply>);
}


FileReply::~FileReply(void)
{
}