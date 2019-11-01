#include "GpioRemoveMsg.h"
#include "Marshaller.h"

GpioRemoveMsg::GpioRemoveMsg(void) :
	m_pin(0)
{

	setName("GpioRemoveMsg");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<GpioRemoveMsg>(*this, (NewMessage_t*)& getNewMessage<GpioRemoveMsg>);

}
