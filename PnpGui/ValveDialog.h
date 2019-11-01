#pragma once
#include <QtWidgets/qdialog.h>
#include "ui_ValveDialog.h"

class ValveDialog :
	public QDialog
{
	Q_OBJECT

public:
	ValveDialog(QWidget* parent = nullptr);

	Ui_ValveDialog* m_dialog;
public slots:
	void actionAddClicked();
	void reject();
	void ioDropDownAction(int32_t index);
	void parameterDropDownAction(int32_t index);

};

