#include "AxisDialog.h"
#include "HighLevelGui.h"
#include "Utils/MathUtils.h"

AxisDialog::AxisDialog(QWidget* parent) :
	QDialog(parent),
	m_valid(false)
{

	m_dialog = new Ui_AxisDialog();
	m_dialog->setupUi(this);

	{
		// Stepper 1
		m_ioSignalBoxes.push_back((m_dialog->signalCombo1));
		m_ioSignalBoxes.push_back((m_dialog->signalCombo2));
		m_ioSignalBoxes.push_back((m_dialog->signalCombo3));
		// Stepper 2
		m_ioSignalBoxes.push_back((m_dialog->signalCombo4));
		m_ioSignalBoxes.push_back((m_dialog->signalCombo5));
		m_ioSignalBoxes.push_back((m_dialog->signalCombo6));
		// Limit Switch
		m_ioSignalBoxes.push_back((m_dialog->signalCombo7));
	}
	{
		// Stepper 1
		m_ioTypeBoxes.push_back(m_dialog->stepperOneIoComboBox);
		m_ioTypeBoxes.push_back(m_dialog->stepperOneIoComboBox2);
		m_ioTypeBoxes.push_back(m_dialog->stepperOneIoComboBox3);

		// Stepper 2
		m_ioTypeBoxes.push_back(m_dialog->stepperTwoIoComboBox);
		m_ioTypeBoxes.push_back(m_dialog->stepperTwoIoComboBox2);
		m_ioTypeBoxes.push_back(m_dialog->stepperTwoIoComboBox3);

		// Limit Switch
		m_ioTypeBoxes.push_back(m_dialog->limitIOTypeBox);

	}
	{
		// Stepper 1
		m_ioTypeLabels.push_back(m_dialog->stepIOLabelP0);
		m_ioTypeLabels.push_back(m_dialog->stepIOLabelP5);
		m_ioTypeLabels.push_back(m_dialog->stepIOLabelP10);

		// Stepper 2
		m_ioTypeLabels.push_back(m_dialog->stepIOLabelP15);
		m_ioTypeLabels.push_back(m_dialog->stepIOLabelP20);
		m_ioTypeLabels.push_back(m_dialog->stepIOLabelP25);

		// Limit Switch
		m_ioTypeLabels.push_back(m_dialog->stepIOLabelP30);

	}
	{
		// Stepper 1
		m_ioParamsVec.push_back(
			{ m_dialog->stepper1ioParam1ComboBox1,
			 m_dialog->stepper1ioParam2ComboBox1,
			 m_dialog->stepper1ioParam3ComboBox1,
			 m_dialog->stepper1ioParam4ComboBox1 }
		);
		m_ioParamsVec.push_back(
			{ m_dialog->stepper1ioParam1ComboBox2,
			 m_dialog->stepper1ioParam2ComboBox2,
			 m_dialog->stepper1ioParam3ComboBox2,
			 m_dialog->stepper1ioParam4ComboBox2 }
		);
		m_ioParamsVec.push_back(
			{ m_dialog->stepper1ioParam1ComboBox3,
			 m_dialog->stepper1ioParam2ComboBox3,
			 m_dialog->stepper1ioParam3ComboBox3,
			 m_dialog->stepper1ioParam4ComboBox3 }
		);
		// Stepper 2
		m_ioParamsVec.push_back(
			{ m_dialog->stepper2ioParam1ComboBox1,
			 m_dialog->stepper2ioParam2ComboBox1,
			 m_dialog->stepper2ioParam3ComboBox1,
			 m_dialog->stepper2ioParam4ComboBox1 }
		);
		m_ioParamsVec.push_back(
			{ m_dialog->stepper2ioParam1ComboBox2,
			 m_dialog->stepper2ioParam2ComboBox2,
			 m_dialog->stepper2ioParam3ComboBox2,
			 m_dialog->stepper2ioParam4ComboBox2 }
		);
		m_ioParamsVec.push_back(
			{ m_dialog->stepper2ioParam1ComboBox3,
			 m_dialog->stepper2ioParam2ComboBox3,
			 m_dialog->stepper2ioParam3ComboBox3,
			 m_dialog->stepper2ioParam4ComboBox3 }
		);

		// Limit Switch
		m_ioParamsVec.push_back(
			{ m_dialog->limitParam1Box,
			 m_dialog->limitParam2Box,
			 m_dialog->limitParam3Box,
			 m_dialog->limitParam4Box }
		);
	}
	{
		// Stepper 1
		m_ioLabelVec.push_back(
			{ m_dialog->stepIOLabelP1,
			 m_dialog->stepIOLabelP2,
			 m_dialog->stepIOLabelP3,
			 m_dialog->stepIOLabelP4 }
		);
		m_ioLabelVec.push_back(
			{ m_dialog->stepIOLabelP6,
			 m_dialog->stepIOLabelP7,
			 m_dialog->stepIOLabelP8,
			 m_dialog->stepIOLabelP9 }
		);
		m_ioLabelVec.push_back(
			{ m_dialog->stepIOLabelP11,
			 m_dialog->stepIOLabelP12,
			 m_dialog->stepIOLabelP13,
			 m_dialog->stepIOLabelP14 }
		);
		// Stepper 2
		m_ioLabelVec.push_back(
			{ m_dialog->stepIOLabelP16,
			 m_dialog->stepIOLabelP17,
			 m_dialog->stepIOLabelP18,
			 m_dialog->stepIOLabelP19 }
		);
		m_ioLabelVec.push_back(
			{ m_dialog->stepIOLabelP21,
			 m_dialog->stepIOLabelP22,
			 m_dialog->stepIOLabelP23,
			 m_dialog->stepIOLabelP24 }
		);
		m_ioLabelVec.push_back(
			{ m_dialog->stepIOLabelP26,
			 m_dialog->stepIOLabelP27,
			 m_dialog->stepIOLabelP28,
			 m_dialog->stepIOLabelP29 }
		);

		// Limit Switch
		m_ioLabelVec.push_back(
			{ m_dialog->stepIOLabelP31,
			 m_dialog->stepIOLabelP32,
			 m_dialog->stepIOLabelP33,
			 m_dialog->stepIOLabelP34 }
		);
	}
	updateGui();
}


void AxisDialog::actionAddClicked()
{

}

void AxisDialog::reject()
{
	updateReturnParams();
	QDialog::reject();
}

void AxisDialog::ioDropDownAction()
{
	updateReturnParams();
	updateGui();
}

void AxisDialog::parameterDropDownAction()
{
	updateReturnParams();
	updateGui();
}

void AxisDialog::ioCountSpinAction()
{
	updateReturnParams();
	updateGui();
}

void AxisDialog::stepperSpinAction()
{
	updateReturnParams();
	updateGui();

}


// This will take in all the current values in the widgets and adjust what is shown in the 
// GUI accordingly. 
void AxisDialog::updateGui()
{
	updateAddBtn();

	uint8_t stepperCnt = m_dialog->stepperCntSpin->value();
	
	for (uint16_t i = 0; i < m_ioTypeBoxes.size(); ++i)
	{
		QComboBox* typeCombo = m_ioTypeBoxes.at(i);
		m_ioTypeBoxes.at(i)->setVisible(true);
		m_ioSignalBoxes.at(i)->setVisible(true);
		m_ioTypeLabels.at(i)->setVisible(true);

		if (typeCombo->currentText() == QString("I2C"))
		{
			for (uint8_t j = 0; j < 4; ++j)
			{
				m_ioParamsVec.at(i).at(j)->setVisible(true);
				m_ioLabelVec.at(i).at(j)->setVisible(true);
			}
		}
		else if (typeCombo->currentText() == QString("GPIO"))
		{
			for (uint8_t j = 0; j < 2; ++j)
			{
				m_ioParamsVec.at(i).at(j)->setVisible(true);
				m_ioLabelVec.at(i).at(j)->setVisible(true);

			}
			for (uint8_t j = 2; j < 4; ++j)
			{
				m_ioParamsVec.at(i).at(j)->setVisible(false);
				m_ioLabelVec.at(i).at(j)->setVisible(false);

			}
		}
		
		if ((i + 1) > ((stepperCnt * 3)) && i != (m_ioParamsVec.size() - 1))
		{
			for (uint8_t j = 0; j < 4; ++j)
			{
				m_ioParamsVec.at(i).at(j)->setVisible(false);
				m_ioLabelVec.at(i).at(j)->setVisible(false);

			}
			m_ioTypeBoxes.at(i)->setVisible(false);
			m_ioSignalBoxes.at(i)->setVisible(false);
			m_ioTypeLabels.at(i)->setVisible(false);

		}


	}

}

void AxisDialog::updateReturnParams()
{
	HighLevelGui* hlg = HighLevelGui::getMgr();

	std::vector<HighLevelGui::IOParameters> ioVec;
	HighLevelGui::AxisParams axisParam;



	uint8_t stepperCnt = m_dialog->stepperCntSpin->value();
	bool isValid = true;

	for (uint16_t i = 0; i < stepperCnt * 3; ++i)
	{

		QComboBox* pBox1 = m_ioParamsVec.at(i).at(0);
		QComboBox* pBox2 = m_ioParamsVec.at(i).at(1);
		QComboBox* pBox3 = m_ioParamsVec.at(i).at(2);
		QComboBox* pBox4 = m_ioParamsVec.at(i).at(3);

		std::string pTextStr2 = pBox2->currentText().toUtf8();
		std::string pTextStr3 = pBox3->currentText().toUtf8();
		std::string pTextStr4 = pBox4->currentText().toUtf8();

		HighLevelGui::IOType ioType;
		HighLevelGui::SignalType signal;
		std::string param1 = pBox1->currentText().toUtf8();
		uint8_t param2 = 0;
		uint8_t param3 = 0;
		uint8_t param4 = 0;

		if (m_ioSignalBoxes.at(i)->currentText() == QString("PUL"))
		{
			signal = HighLevelGui::SignalType::STEPPER_PUL;
		}
		else if (m_ioSignalBoxes.at(i)->currentText() == QString("DIR"))
		{
			signal = HighLevelGui::SignalType::STEPPER_DIR;
		}
		else if (m_ioSignalBoxes.at(i)->currentText() == QString("EN"))
		{
			signal = HighLevelGui::SignalType::STEPPER_EN;
		}
		else
		{
			isValid = false;
		}


		if (m_ioTypeBoxes.at(i)->currentText() == QString("I2C"))
		{
			if (MathUtils::isHex(pTextStr2) &&
				MathUtils::isHex(pTextStr3) &&
				MathUtils::isHex(pTextStr4))
			{
				ioType = HighLevelGui::IOType::I2C;
				param2 = MathUtils::getDigit(pTextStr2);
				param3 = MathUtils::getDigit(pTextStr3);
				param4 = MathUtils::getDigit(pTextStr4);
				axisParam.m_limitSwitch = HighLevelGui::IOParameters(
					ioType,
					signal,
					param1,
					param2,
					param3,
					param4
				);
			}
			else
			{
				isValid = false;

			}
		}
		else if (m_ioTypeBoxes.at(i)->currentText() == QString("GPIO"))
		{
			if (MathUtils::isDigit(pTextStr2))
			{
				ioType = HighLevelGui::IOType::GPIO;
				param2 = MathUtils::getDigit(pTextStr2);
				axisParam.m_limitSwitch = HighLevelGui::IOParameters(
					ioType,
					signal,
					param1,
					param2,
					param3,
					param4
				);
			}
			else
			{
				isValid = false;

			}

		}

		
		ioVec.emplace_back(ioType, signal, param1, param2, param3, param4);



	}

	// Limit Switch
	{


		QComboBox* pBox1 = m_ioParamsVec.at(LIMIT_INDEX).at(0);
		QComboBox* pBox2 = m_ioParamsVec.at(LIMIT_INDEX).at(1);
		QComboBox* pBox3 = m_ioParamsVec.at(LIMIT_INDEX).at(2);
		QComboBox* pBox4 = m_ioParamsVec.at(LIMIT_INDEX).at(3);

		std::string pTextStr2 = pBox2->currentText().toUtf8();
		std::string pTextStr3 = pBox3->currentText().toUtf8();
		std::string pTextStr4 = pBox4->currentText().toUtf8();

		HighLevelGui::IOType ioType;
		HighLevelGui::SignalType signal = HighLevelGui::SignalType::GENERIC_IN;
		std::string param1 = pBox1->currentText().toUtf8();
		uint8_t param2 = 0;
		uint8_t param3 = 0;
		uint8_t param4 = 0;

		if (m_ioTypeBoxes.at(LIMIT_INDEX)->currentText() == QString("I2C"))
		{
			if (MathUtils::isHex(pTextStr2) &&
				MathUtils::isHex(pTextStr3) &&
				MathUtils::isHex(pTextStr4))
			{
				ioType = HighLevelGui::IOType::I2C;
				param2 = MathUtils::getDigit(pTextStr2);
				param3 = MathUtils::getDigit(pTextStr3);
				param4 = MathUtils::getDigit(pTextStr4);
				axisParam.m_limitSwitch = HighLevelGui::IOParameters(ioType, HighLevelGui::SignalType::GENERIC_IN, param1, param2, param3, param4);
			}
			else
			{
				isValid = false;

			}
		}
		else if (m_ioTypeBoxes.at(LIMIT_INDEX)->currentText() == QString("GPIO"))
		{
			if (MathUtils::isDigit(pTextStr2))
			{
				ioType = HighLevelGui::IOType::GPIO;
				param2 = MathUtils::getDigit(pTextStr2);
				axisParam.m_limitSwitch = HighLevelGui::IOParameters(ioType, HighLevelGui::SignalType::GENERIC_IN, param1, param2, param3, param4);

			}
			else
			{
				isValid = false;

			}

		}
	
	}

	if (isValid)
	{
		axisParam.m_ioParams = ioVec;
		axisParam.m_ioCnt = ioVec.size();
		axisParam.m_stepperCnt = stepperCnt;
		axisParam.m_axisName = m_dialog->axisNameBox->currentText().toUtf8();
		axisParam.m_axisLen = m_dialog->axisLenSpin->value();



		m_valid = isValid;
		updateAddBtn();

	}
}




void AxisDialog::updateAddBtn()
{
	if (m_valid)
	{
		m_dialog->addBtn->setEnabled(true);

	}
	else
	{
		m_dialog->addBtn->setEnabled(false);
	}
}

//HighLevelGui::IOParameters AxisDialog::getIoParams(uint8_t i)
//{
	//if (i < MAX_IO)
		//HighLevelGui::IOType type;



	//return HighLevelGui::IOParameters();
//}
