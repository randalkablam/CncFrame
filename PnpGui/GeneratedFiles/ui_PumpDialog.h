/********************************************************************************
** Form generated from reading UI file 'PumpDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUMPDIALOG_H
#define UI_PUMPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PumpDialog
{
public:
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QComboBox *paramCombo6;
    QLabel *label_16;
    QComboBox *paramCombo7;
    QLabel *paramLabel1;
    QLabel *paramLabel8;
    QLabel *paramLabel3;
    QComboBox *paramCombo2;
    QComboBox *paramCombo4;
    QLabel *paramLabel4;
    QComboBox *paramCombo1;
    QComboBox *ioCombo2;
    QLabel *paramLabel2;
    QComboBox *ioCombo1;
    QComboBox *paramCombo8;
    QComboBox *paramCombo5;
    QLabel *label;
    QLabel *paramLabel7;
    QComboBox *paramCombo3;
    QLabel *paramLabel5;
    QLabel *paramLabel6;
    QSpinBox *ioCountSpin2;
    QLabel *label_28;
    QLabel *label_27;
    QSpinBox *ioCountSpin1;

    void setupUi(QDialog *PumpDialog)
    {
        if (PumpDialog->objectName().isEmpty())
            PumpDialog->setObjectName(QStringLiteral("PumpDialog"));
        PumpDialog->resize(400, 300);
        addBtn = new QPushButton(PumpDialog);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setEnabled(false);
        addBtn->setGeometry(QRect(300, 230, 75, 23));
        cancelBtn = new QPushButton(PumpDialog);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(300, 260, 75, 23));
        paramCombo6 = new QComboBox(PumpDialog);
        paramCombo6->setObjectName(QStringLiteral("paramCombo6"));
        paramCombo6->setGeometry(QRect(120, 180, 69, 22));
        label_16 = new QLabel(PumpDialog);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 110, 47, 13));
        paramCombo7 = new QComboBox(PumpDialog);
        paramCombo7->setObjectName(QStringLiteral("paramCombo7"));
        paramCombo7->setEnabled(true);
        paramCombo7->setGeometry(QRect(210, 180, 69, 22));
        paramCombo7->setEditable(false);
        paramCombo7->setMaxVisibleItems(10);
        paramCombo7->setFrame(true);
        paramLabel1 = new QLabel(PumpDialog);
        paramLabel1->setObjectName(QStringLiteral("paramLabel1"));
        paramLabel1->setGeometry(QRect(20, 60, 71, 16));
        paramLabel8 = new QLabel(PumpDialog);
        paramLabel8->setObjectName(QStringLiteral("paramLabel8"));
        paramLabel8->setGeometry(QRect(300, 160, 71, 16));
        paramLabel3 = new QLabel(PumpDialog);
        paramLabel3->setObjectName(QStringLiteral("paramLabel3"));
        paramLabel3->setGeometry(QRect(210, 60, 61, 16));
        paramCombo2 = new QComboBox(PumpDialog);
        paramCombo2->setObjectName(QStringLiteral("paramCombo2"));
        paramCombo2->setGeometry(QRect(120, 80, 69, 22));
        paramCombo4 = new QComboBox(PumpDialog);
        paramCombo4->setObjectName(QStringLiteral("paramCombo4"));
        paramCombo4->setGeometry(QRect(300, 80, 69, 22));
        paramLabel4 = new QLabel(PumpDialog);
        paramLabel4->setObjectName(QStringLiteral("paramLabel4"));
        paramLabel4->setGeometry(QRect(300, 60, 71, 16));
        paramCombo1 = new QComboBox(PumpDialog);
        paramCombo1->setObjectName(QStringLiteral("paramCombo1"));
        paramCombo1->setGeometry(QRect(20, 80, 69, 22));
        ioCombo2 = new QComboBox(PumpDialog);
        ioCombo2->addItem(QString());
        ioCombo2->addItem(QString());
        ioCombo2->setObjectName(QStringLiteral("ioCombo2"));
        ioCombo2->setGeometry(QRect(20, 130, 69, 22));
        paramLabel2 = new QLabel(PumpDialog);
        paramLabel2->setObjectName(QStringLiteral("paramLabel2"));
        paramLabel2->setGeometry(QRect(120, 60, 71, 16));
        ioCombo1 = new QComboBox(PumpDialog);
        ioCombo1->addItem(QString());
        ioCombo1->addItem(QString());
        ioCombo1->setObjectName(QStringLiteral("ioCombo1"));
        ioCombo1->setGeometry(QRect(20, 30, 69, 22));
        paramCombo8 = new QComboBox(PumpDialog);
        paramCombo8->setObjectName(QStringLiteral("paramCombo8"));
        paramCombo8->setGeometry(QRect(300, 180, 69, 22));
        paramCombo5 = new QComboBox(PumpDialog);
        paramCombo5->setObjectName(QStringLiteral("paramCombo5"));
        paramCombo5->setGeometry(QRect(20, 180, 69, 22));
        label = new QLabel(PumpDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 47, 13));
        paramLabel7 = new QLabel(PumpDialog);
        paramLabel7->setObjectName(QStringLiteral("paramLabel7"));
        paramLabel7->setGeometry(QRect(210, 160, 61, 16));
        paramCombo3 = new QComboBox(PumpDialog);
        paramCombo3->setObjectName(QStringLiteral("paramCombo3"));
        paramCombo3->setEnabled(true);
        paramCombo3->setGeometry(QRect(210, 80, 69, 22));
        paramCombo3->setEditable(false);
        paramCombo3->setMaxVisibleItems(10);
        paramCombo3->setFrame(true);
        paramLabel5 = new QLabel(PumpDialog);
        paramLabel5->setObjectName(QStringLiteral("paramLabel5"));
        paramLabel5->setGeometry(QRect(20, 160, 71, 16));
        paramLabel6 = new QLabel(PumpDialog);
        paramLabel6->setObjectName(QStringLiteral("paramLabel6"));
        paramLabel6->setGeometry(QRect(120, 160, 71, 16));
        ioCountSpin2 = new QSpinBox(PumpDialog);
        ioCountSpin2->setObjectName(QStringLiteral("ioCountSpin2"));
        ioCountSpin2->setGeometry(QRect(110, 130, 42, 22));
        ioCountSpin2->setMaximum(4);
        label_28 = new QLabel(PumpDialog);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(110, 110, 47, 13));
        label_27 = new QLabel(PumpDialog);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(110, 10, 47, 13));
        ioCountSpin1 = new QSpinBox(PumpDialog);
        ioCountSpin1->setObjectName(QStringLiteral("ioCountSpin1"));
        ioCountSpin1->setGeometry(QRect(110, 30, 42, 22));
        ioCountSpin1->setMaximum(4);

        retranslateUi(PumpDialog);
        QObject::connect(addBtn, SIGNAL(clicked()), PumpDialog, SLOT(actionAddClicked()));
        QObject::connect(cancelBtn, SIGNAL(clicked()), PumpDialog, SLOT(reject()));
        QObject::connect(ioCombo1, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(ioDropDownAction()));
        QObject::connect(ioCombo2, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(ioDropDownAction()));
        QObject::connect(paramCombo1, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo2, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo3, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo4, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo5, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo6, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo7, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo8, SIGNAL(currentIndexChanged(int)), PumpDialog, SLOT(parameterDropDownAction()));

        QMetaObject::connectSlotsByName(PumpDialog);
    } // setupUi

    void retranslateUi(QDialog *PumpDialog)
    {
        PumpDialog->setWindowTitle(QApplication::translate("PumpDialog", "Dialog", nullptr));
        addBtn->setText(QApplication::translate("PumpDialog", "Add", nullptr));
        cancelBtn->setText(QApplication::translate("PumpDialog", "Cancel", nullptr));
        label_16->setText(QApplication::translate("PumpDialog", "I/O Type", nullptr));
        paramLabel1->setText(QApplication::translate("PumpDialog", "Parameter 1", nullptr));
        paramLabel8->setText(QApplication::translate("PumpDialog", "Parameter 4", nullptr));
        paramLabel3->setText(QApplication::translate("PumpDialog", "Parameter 3", nullptr));
        paramLabel4->setText(QApplication::translate("PumpDialog", "Parameter 4", nullptr));
        ioCombo2->setItemText(0, QApplication::translate("PumpDialog", "I2C", nullptr));
        ioCombo2->setItemText(1, QApplication::translate("PumpDialog", "GPIO", nullptr));

        paramLabel2->setText(QApplication::translate("PumpDialog", "Parameter 2", nullptr));
        ioCombo1->setItemText(0, QApplication::translate("PumpDialog", "I2C", nullptr));
        ioCombo1->setItemText(1, QApplication::translate("PumpDialog", "GPIO", nullptr));

        label->setText(QApplication::translate("PumpDialog", "I/O Type", nullptr));
        paramLabel7->setText(QApplication::translate("PumpDialog", "Parameter 3", nullptr));
        paramLabel5->setText(QApplication::translate("PumpDialog", "Parameter 1", nullptr));
        paramLabel6->setText(QApplication::translate("PumpDialog", "Parameter 2", nullptr));
        label_28->setText(QApplication::translate("PumpDialog", "IO Count", nullptr));
        label_27->setText(QApplication::translate("PumpDialog", "IO Count", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PumpDialog: public Ui_PumpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUMPDIALOG_H
