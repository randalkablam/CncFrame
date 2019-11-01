#include "SetFileMapping.h"
#include "Marshaller.h"


SetFileMapping::SetFileMapping(void) : 
	m_filename(""),
	m_alias("")
{
	setName("SetFileMapping");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<SetFileMapping>(*this, (NewMessage_t*)& getNewMessage<SetFileMapping>);

}


SetFileMapping::~SetFileMapping(void)
{
}