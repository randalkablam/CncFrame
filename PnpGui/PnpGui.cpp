#include "PnpGui.h"
#include <iostream>
#include "ConfigDialog.h"
#include "ConfigSelectDialog.h"
#include "QDialogCast.h"
#include "PnpMaster/Configuration/ConfigurationMessage.h"

#include "HighLevelGui.h"


PnpGui::PnpGui(HighLevelGui* hlg, QWidget *parent )
	: QMainWindow(parent),
	m_highLevelGui(hlg)
{
	ui.setupUi(this);
}

void PnpGui::actionOpenConfig(bool checked)
{
	ConfigSelectDialog* dialog = new ConfigSelectDialog(this);
	dialog->show();
	std::cout << "world" << std::endl;
}


void PnpGui::actionNewConfig(bool checked)
{

	//ConfigDialog* dialog = new ConfigDialog(this);
	//dialog->show();
	
	AxisConfigMsg axisConfig;
	meta::generateDialog(axisConfig);

	std::cout << "Hello" << std::endl;

}

void PnpGui::actionAirOnClick()
{
}

void PnpGui::actionHomeClick()
{
}

void PnpGui::actionXaxisMove(int32_t i)
{
}

void PnpGui::actionYaxisMove(int32_t i)
{
}

void PnpGui::counterZAxis(double d)
{
}

void PnpGui::counterYAxis(double d)
{
}

void PnpGui::counterXAxis(double d)
{
}

void PnpGui::dragView(QRect rect, QPointF start, QPointF end)
{
}

void PnpGui::cmdEntered(void)
{
	std::string val = ui.cmdLine->text().toLocal8Bit().constData();
	ui.cmdBrowser->append(ui.cmdLine->text());

	m_highLevelGui->sendCmd(val);

}

void PnpGui::cmdDestChanged(QString& str)
{
	std::string val = str.toLocal8Bit().constData();
	m_highLevelGui->updateCmdDest(val);

}
