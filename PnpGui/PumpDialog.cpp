#include "PumpDialog.h"
PumpDialog::PumpDialog(QWidget* parent) :
	QDialog(parent)
{

	m_dialog = new Ui_PumpDialog();
	m_dialog->setupUi(this);


}


void PumpDialog::actionAddClicked()
{

}

void PumpDialog::reject()
{
	QDialog::reject();
}

void PumpDialog::ioDropDownAction(int32_t index)
{
}

void PumpDialog::parameterDropDownAction(int32_t index)
{
}
