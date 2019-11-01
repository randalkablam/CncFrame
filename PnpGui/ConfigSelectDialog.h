#pragma once
#include <qdialog.h>
#include "ui_configSelect.h"

class ConfigSelectDialog :
	public QDialog
{
	Q_OBJECT

public:
	ConfigSelectDialog(QWidget* parent = nullptr);

	Ui_ConfigSelect* m_dialog;
public slots:
	void actionOpenClicked();
	void actionNewClicked();
	void reject();
	void actionBrowseClicked();
};

