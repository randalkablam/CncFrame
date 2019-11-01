#include "ValveConfigMsg.h"
#include "Marshaller.h"


ValveConfigMsg::ValveConfigMsg(void) :
	m_valveVec()
{
	setName("ValveConfigMsg");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<ValveConfigMsg>(*this, (NewMessage_t*)& getNewMessage<ValveConfigMsg>);

}


ValveConfigMsg::~ValveConfigMsg(void)
{
}
