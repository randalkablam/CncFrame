#pragma once
#include <QtWidgets/qdialog.h>
#include "ui_PumpDialog.h"
class PumpDialog :
	public QDialog
{
	Q_OBJECT

public:
	PumpDialog(QWidget* parent = nullptr);

	Ui_PumpDialog* m_dialog;
public slots:
	void actionAddClicked();
	void reject();
	void ioDropDownAction(int32_t index);
	void parameterDropDownAction(int32_t index);
};

