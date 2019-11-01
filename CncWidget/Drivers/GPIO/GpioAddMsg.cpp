#include "GpioAddMsg.h"
#include "Marshaller.h"

GpioAddMsg::GpioAddMsg() : 
	m_pin(0)
{

	setName("GpioAddMsg");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<GpioAddMsg>(*this, (NewMessage_t*)& getNewMessage<GpioAddMsg>);

}