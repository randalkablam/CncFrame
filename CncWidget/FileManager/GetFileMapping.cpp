#include "GetFileMapping.h"
#include "Marshaller.h"


GetFileMapping::GetFileMapping(void) :
	m_nameVec()
{
	setName("GetFileMapping");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<GetFileMapping>(*this, (NewMessage_t*)& getNewMessage<GetFileMapping>);
}


GetFileMapping::~GetFileMapping(void)
{
}
