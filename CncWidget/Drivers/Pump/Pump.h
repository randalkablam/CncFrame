#pragma once

#include "Drivers/DriverBase.h"
#include "Drivers/DcMotor/DcMotor.h"

class Pump : public DriverBase
{
public:
	Pump(std::string i2cName, uint8_t i2cDev, uint8_t i2cReg);
	Pump();
	~Pump();

	

	const DcMotor& getDcMotor() const;
	void setDcMotor(const DcMotor& dc);
private:
	DcMotor m_dcMotor;
};






#include "MetaLib/Meta.h"
namespace meta
{


	template <>
	inline auto registerMembers<Pump>()
	{
		return members(
			member("DcMotor", &Pump::getDcMotor, &Pump::setDcMotor)
		);
	}

}