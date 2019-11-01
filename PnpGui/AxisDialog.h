#pragma once
#include <QtWidgets/qdialog.h>
#include "ui_AxisDialog.h"

class AxisDialog :
	public QDialog
{
	Q_OBJECT

public:
	// Pass in axis configuration object for this dialog to populate
	AxisDialog(QWidget* parent = nullptr);

	Ui_AxisDialog* m_dialog;
public slots:
	void actionAddClicked();
	void reject();
	void ioDropDownAction();
	void parameterDropDownAction();
	void ioCountSpinAction();
	void stepperSpinAction();

private:
	void updateGui();
	void updateReturnParams();

	bool m_valid;

	void updateAddBtn();
	const uint8_t MAX_IO = 7;

	

	std::vector<QComboBox*> m_ioTypeBoxes;
	std::vector<std::vector<QComboBox*>> m_ioParamsVec;
	std::vector<QComboBox*> m_ioSignalBoxes;

	std::vector<std::vector<QLabel*>> m_ioLabelVec;
	std::vector<QLabel*> m_ioTypeLabels;
	
	const uint16_t LIMIT_INDEX = 6;

	
};

