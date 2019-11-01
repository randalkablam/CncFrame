#include "GpioValueMsg.h"
#include "Marshaller.h"

GpioValueMsg::GpioValueMsg() : 
	m_pin(0)
{

	setName("GpioValueMsg");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<GpioValueMsg>(*this, (NewMessage_t*)& getNewMessage<GpioValueMsg>);

}