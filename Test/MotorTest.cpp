#include "MotorTest.h"

MotorTest::MotorTest() :
	m_x(X_LEN),
	m_y(Y_LEN),
	m_z(Z_LEN)
{
	m_x.setResolution(1);
	m_x.setUnitType(Unit_t::MIL);

	m_y.setResolution(1);
	m_y.setUnitType(Unit_t::MIL);


	m_z.setResolution(1);
	m_z.setUnitType(Unit_t::MIL);

}

void MotorTest::testLoop()
{

	while (1)
	{

		char c;

		std::cin >> c;

		if (c == 'q')
		{
			break;

		}
		else if (c == 'x')
		{
			double val;
			std::cin >> val;
			moveX(val);
		}
		else if (c == 'y')
		{
			double val;
			std::cin >> val;
			moveY(val);
		}
		else if (c == 'z')
		{
			double val;
			std::cin >> val;
			moveZ(val);
		}


	}



}

bool MotorTest::moveX(double mil)
{
	m_x.moveAbsolute(mil);
	return true;
}

bool MotorTest::moveY(double mil)
{
	m_y.moveAbsolute(mil);
	return true;
}

bool MotorTest::moveZ(double mil)
{
	m_z.moveAbsolute(mil);
	return true;
}
