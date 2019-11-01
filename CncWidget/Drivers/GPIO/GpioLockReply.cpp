#include "GpioLockReply.h"
#include "Marshaller.h"

GpioLockReply::GpioLockReply(void) :
	m_pin(0),
	m_gpioDriverPtr(0)
{

	setName("GpioLockReply");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<GpioLockReply>(*this, (NewMessage_t*)& getNewMessage<GpioLockReply>);

}
