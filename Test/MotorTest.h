#pragma once
#include "Drivers/Axis/AxisGeneric.h"
#include "Drivers/Axis/AxisX.h"
#include "Drivers/Axis/AxisY.h"
#include "Drivers/Axis/AxisZ.h"

const double X_LEN = 1000 * 20;
const double Y_LEN = 1000 * 10;
const double Z_LEN = 1000 * 2;
class MotorTest
{
public:

	MotorTest();
	void testLoop();

	bool moveX(double mil);
	bool moveY(double mil);
	bool moveZ(double mil);

	AxisX m_x;
	AxisY m_y;
	AxisZ m_z;
};

