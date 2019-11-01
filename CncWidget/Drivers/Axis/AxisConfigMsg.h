#pragma once
#include "Message.h"
#include "AxisGeneric.h"
Derive_Message_CRTP(AxisConfigMsg)
{
public:
	AxisConfigMsg();
	~AxisConfigMsg(void);

	const std::vector<AxisGeneric>& getAxisVec() const;

	void setAxisVec(const std::vector<AxisGeneric>& axisVec);
	bool validateAxisVec(const std::vector<AxisGeneric>& axisVec);

	std::vector<AxisGeneric> m_axisVec;
};

#include <MetaLib/Meta.h>


namespace meta
{


	template <>
	inline auto registerMembers<AxisConfigMsg>()
	{
		return members(
			member("m_axisVec", &AxisConfigMsg::getAxisVec, &AxisConfigMsg::setAxisVec, &AxisConfigMsg::validateAxisVec)
		);
	}

}