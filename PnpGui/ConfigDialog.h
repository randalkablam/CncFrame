#pragma once
#include "QtWidgets/qdialog.h"
#include "ui_ConfigDialog.h"

class ConfigDialog :
	public QDialog
{
	Q_OBJECT

public:
	ConfigDialog(QWidget* parent = nullptr);

	Ui_ConfigDialog* m_dialog;

public slots:
	void actionAddValveClicked();
	void actionSaveClicked();
	void actionAddPumpClicked();
	void reject();
	void actionAddAxisClicked();
	void actionAddMgrClicked();
	void actionAddLocClicked();


private:
	void updateAxisTable();


	void provideContextMenu(const QPoint&); // MainWindow.h

};

