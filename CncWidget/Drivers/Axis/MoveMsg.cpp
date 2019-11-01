#include "MoveMsg.h"
#include "Marshaller.h"


MoveMsg::MoveMsg(void) :
	m_axisId(AxisName_t::UNKNOWN),
	m_position(0),
	m_unitType(Unit_t::MILLIMETER)
{
	setName("MoveMsg");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<MoveMsg>(*this, (NewMessage_t*)& getNewMessage<MoveMsg>);

}


MoveMsg::~MoveMsg(void)
{
}
