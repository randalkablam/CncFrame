#include "AxisConfigMsg.h"
#include "Marshaller.h"


AxisConfigMsg::AxisConfigMsg(void) :
	m_axisVec()
{
	setName("AxisConfigMsg");
	Marshaller* marshall = Marshaller::getMarshaller();

	marshall->registerMessageName<AxisConfigMsg>(*this, (NewMessage_t*)& getNewMessage<AxisConfigMsg>);

}


AxisConfigMsg::~AxisConfigMsg(void)
{
}

const std::vector<AxisGeneric>& AxisConfigMsg::getAxisVec() const
{
	return m_axisVec;
}

void AxisConfigMsg::setAxisVec(const std::vector<AxisGeneric>& axisVec)
{
	m_axisVec = axisVec;
}

bool AxisConfigMsg::validateAxisVec(const std::vector<AxisGeneric>& axisVec)
{
	bool ret = true;
	std::map<AxisName_t, bool> nameMap =
	{
		{AxisName_t::A_AXIS, false},
		{AxisName_t::B_AXIS, false},
		{AxisName_t::C_AXIS, false},
		{AxisName_t::X_AXIS, false},
		{AxisName_t::Y_AXIS, false},
		{AxisName_t::Z_AXIS, false},
		{AxisName_t::UNKNOWN, true}// if unknown then invalid
	};
	auto it = axisVec.begin();
	auto endIt = axisVec.end();
	while(it != endIt)
	{
		if (nameMap[(*it).getAxisName()])
		{
			ret = false;
		}
		else
		{
			nameMap[(*it).getAxisName()] = true;
		}
		++it;
	}
	

	return ret;
}
