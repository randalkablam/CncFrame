#include "ConfigSelectDialog.h"
ConfigSelectDialog::ConfigSelectDialog(QWidget* parent) :
	QDialog(parent)
{

	m_dialog = new Ui_ConfigSelect();
	m_dialog->setupUi(this);


}


void ConfigSelectDialog::actionOpenClicked()
{


}

void ConfigSelectDialog::actionNewClicked()
{


}

void ConfigSelectDialog::reject()
{
	QDialog::reject();
}

void ConfigSelectDialog::actionBrowseClicked()
{


}
