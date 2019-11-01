#include "FileRequest.h"
#include "Marshaller.h"

FileRequest::FileRequest(void) :
	m_filename(""),
	m_sizeRequested(0),
	m_close(true)
{
	setName("FileRequest");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<FileRequest>(*this, (NewMessage_t*)& getNewMessage<FileRequest>);
}


FileRequest::~FileRequest(void)
{
}