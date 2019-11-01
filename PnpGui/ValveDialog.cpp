#include "ValveDialog.h"
ValveDialog::ValveDialog(QWidget* parent) :
	QDialog(parent)
{

	m_dialog = new Ui_ValveDialog();
	m_dialog->setupUi(this);


}


void ValveDialog::actionAddClicked()
{

}

void ValveDialog::reject()
{
	QDialog::reject();
}

void ValveDialog::ioDropDownAction(int32_t index)
{
}

void ValveDialog::parameterDropDownAction(int32_t index)
{
}
