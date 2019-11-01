#include "ConfigDialog.h"
#include <iostream>
#include "ValveDialog.h"
#include "PumpDialog.h"
#include "AxisDialog.h"
#include "qmenu.h"

ConfigDialog::ConfigDialog(QWidget* parent) :
	QDialog(parent)
{

	m_dialog = new Ui_ConfigDialog();
	m_dialog->setupUi(this);
	m_dialog->machineList->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(m_dialog->machineList, SIGNAL(customContextMenuRequested(const QPoint&)),
		this, SLOT(provideContextMenu(const QPoint&)));

}

void ConfigDialog::actionAddValveClicked()
{
	ValveDialog* dialog = new ValveDialog(this);
	int32_t ret = dialog->exec();
}
void ConfigDialog::actionSaveClicked()
{
	
}
void ConfigDialog::actionAddPumpClicked()
{
	PumpDialog* dialog = new PumpDialog(this);
	int32_t ret = dialog->exec();
}
void ConfigDialog::reject()
{
	std::cout << "hello world" << std::endl;
	QDialog::reject();
}
void ConfigDialog::actionAddAxisClicked()
{
	AxisDialog* dialog = new AxisDialog(this);
	int32_t ret = dialog->exec();

	if (QDialog::Rejected == ret)
	{
	}
	else if (QDialog::Accepted == ret)
	{
		// Update table/gui
		updateAxisTable();


	}
	else
	{
		// Do nothing
	}

}
void ConfigDialog::actionAddMgrClicked()
{

}
void ConfigDialog::actionAddLocClicked()
{

}

void ConfigDialog::updateAxisTable()
{
	QListWidget* list = m_dialog->machineList;

	//QListWidgetItem 

	//list->addItem()




}


void ConfigDialog::provideContextMenu(const QPoint& pos)
{
	QPoint item = m_dialog->machineList->mapToGlobal(pos);
	QMenu submenu;
	submenu.addAction("Edit");
	submenu.addAction("Delete");
	QAction* rightClickItem = submenu.exec(item);
	if (rightClickItem && rightClickItem->text().contains("Delete"))
	{
		m_dialog->machineList->takeItem(m_dialog->machineList->indexAt(pos).row());
	}
}