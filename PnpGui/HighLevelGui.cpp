#include "HighLevelGui.h"
#include "Utils/PnpDefs.h"
#include "PnpGui.h"
#include <QtWidgets/QApplication>
#include "PnpMaster/Configuration/ConfigurationMessage.h"
#include "NameServer.h"
#include "CmdMessage.h"


HighLevelGui* HighLevelGui::ms_highLevelGuiPtr = HighLevelGui::getMgr();


HighLevelGui::HighLevelGui() :
	Manager(ManagerNames::HIGH_LEVEL_GUI_NAME),
	m_cmdDestMgr(ManagerNames::HIGH_LEVEL_GUI_NAME)

{
}


HighLevelGui::~HighLevelGui()
{
}


bool HighLevelGui::populateAxisConfig(AxisParams& params)
{
	// Return whether provided parameters are valid or not
	// if they are then copy them into the configuration message
	bool ret = false;
	uint8_t MAX_IO = 6;
	uint8_t MIN_IO = 3;

	std::vector<IOParameters> ioVec = params.m_ioParams;
	AxisGeneric::StepperVec_t steppers;
	if (params.isValid())
	{
		for (uint8_t i = 0; i < ioVec.size(); i+=3)
		{
			IOParameters ioEn = ioVec[i];
			IOParameters ioDir = ioVec[i];
			IOParameters ioPul = ioVec[i];

			for (uint8_t j = 0; j < 3; j++)
			{
				

				if (SignalType::STEPPER_DIR == ioVec[i+j].m_signal)
				{
					ioDir = ioVec[i + j];
				}
				else if (SignalType::STEPPER_EN == ioVec[i+j].m_signal)
				{
					ioEn = ioVec[i + j];
				}
				else if (SignalType::STEPPER_PUL == ioVec[i+j].m_signal)
				{
					ioPul = ioVec[i + j];

				}
				
			}
			I2cSet enSet(ioEn.m_param1, ioEn.m_param2, ioEn.m_param3);
			I2cSet dirSet(ioDir.m_param1, ioDir.m_param2, ioDir.m_param3);

			steppers.emplace_back(enSet, dirSet);
		}
		AxisGeneric axis;
		axis.setSteppers(steppers);
		//axis.setAxisName(params.m_axisName);
		axis.setLength(params.m_axisLen);
		// TODO get unit type and resolution

		m_configMsg.m_axisConfig.m_axisVec.push_back(axis);

		ret = true;

	}
	else
	{

	}



	return ret;

}

bool HighLevelGui::populateValveConfig(const std::vector<IOParameters>& params)
{
	// Return whether provided parameters are valid or not
	// if they are then copy them into the configuration message
	bool ret = false;
	uint8_t MAX_IO = 2;
	uint8_t MIN_IO = 1;
	if (params.size() <= MAX_IO && params.size() >= MIN_IO)
	{
		for (uint8_t i = 0; i < params.size(); i++)
		{
			if (SignalType::GENERIC_OUT == params[i].m_signal)
			{
				m_configMsg.m_valveConfig.m_valveVec.push_back(Valve(params[i].m_param1, params[i].m_param2, params[i].m_param3));
				ret = true;
			}

		}

	}
	else
	{
	}

	return ret;
}

bool HighLevelGui::populatePumpConfig(const std::vector<IOParameters>& params)
{
	// Return whether provided parameters are valid or not
	// if they are then copy them into the configuration message
	bool ret = false;
	uint8_t MAX_IO = 2;
	uint8_t MIN_IO = 1;
	if (params.size() <= MAX_IO && params.size() >= MIN_IO)
	{
		for (uint8_t i = 0; i < params.size(); i++)
		{
			if (SignalType::GENERIC_OUT == params[i].m_signal)
			{
				m_configMsg.m_pumpConfig.m_pumpVec.push_back(Pump(params[i].m_param1, params[i].m_param2, params[i].m_param3));
				ret = true;
			}

		}

	}
	else
	{
	}


	return ret;

}


void HighLevelGui::sendCmd(const std::string& cmd)
{
	NameServer* ns = NameServer::getNameServer();

	Location* loc = ns->getLocation(m_cmdDestMgr);
	if (nullptr != loc)
	{

		CmdMessage* cmdMsg = new CmdMessage(cmd);


		loc->enqueueItem(cmdMsg);


	}
}

void HighLevelGui::updateCmdDest(const std::string& cmdDest)
{
	m_cmdDestMgr = cmdDest;
}




// Basic Manager Methods
HighLevelGui* HighLevelGui::getMgr()
{
	if (nullptr == ms_highLevelGuiPtr)
	{
		ms_highLevelGuiPtr = new HighLevelGui();


	}
	return ms_highLevelGuiPtr;
}


void HighLevelGui::Start()
{
	char* argv[] = { nullptr };
	int argc = 0;
	QApplication a(argc, argv);
	QWidget* widget = nullptr;
	m_pnpGui = new PnpGui(this, widget);
	m_pnpGui->show();
	a.exec();

	std::cout << getName() << " Initialize()" << std::endl;
}
bool HighLevelGui::Run()
{
	std::cout << getName() << " Run()" << std::endl;
	return true;
}
void HighLevelGui::Stop()
{
	std::cout << getName() << " Terminate()" << std::endl;
}


