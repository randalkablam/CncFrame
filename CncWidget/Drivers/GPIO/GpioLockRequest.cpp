#include "GpioLockRequest.h"
#include "Marshaller.h"

GpioLockRequest::GpioLockRequest(void) :
	m_pin(0),
	m_lock(true)
{

	setName("GpioLockRequest");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<GpioLockRequest>(*this, (NewMessage_t*)& getNewMessage<GpioLockRequest>);


}
