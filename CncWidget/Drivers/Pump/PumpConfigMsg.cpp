#include "PumpConfigMsg.h"
#include "Marshaller.h"


PumpConfigMsg::PumpConfigMsg(void) :
	m_pumpVec()
{
	setName("PumpConfigMsg");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<PumpConfigMsg>(*this, (NewMessage_t*)& getNewMessage<PumpConfigMsg>);

}


PumpConfigMsg::~PumpConfigMsg(void)
{
}
