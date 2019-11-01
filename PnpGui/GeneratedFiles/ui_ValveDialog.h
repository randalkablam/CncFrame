/********************************************************************************
** Form generated from reading UI file 'ValveDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALVEDIALOG_H
#define UI_VALVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ValveDialog
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
    QLabel *label_31;
    QLabel *label_27;
    QSpinBox *ioCountSpin1;

    void setupUi(QDialog *ValveDialog)
    {
        if (ValveDialog->objectName().isEmpty())
            ValveDialog->setObjectName(QStringLiteral("ValveDialog"));
        ValveDialog->resize(400, 300);
        addBtn = new QPushButton(ValveDialog);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setEnabled(false);
        addBtn->setGeometry(QRect(310, 240, 75, 23));
        cancelBtn = new QPushButton(ValveDialog);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(310, 270, 75, 23));
        paramCombo6 = new QComboBox(ValveDialog);
        paramCombo6->setObjectName(QStringLiteral("paramCombo6"));
        paramCombo6->setGeometry(QRect(120, 190, 69, 22));
        label_16 = new QLabel(ValveDialog);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 120, 47, 13));
        paramCombo7 = new QComboBox(ValveDialog);
        paramCombo7->setObjectName(QStringLiteral("paramCombo7"));
        paramCombo7->setEnabled(true);
        paramCombo7->setGeometry(QRect(210, 190, 69, 22));
        paramCombo7->setEditable(false);
        paramCombo7->setMaxVisibleItems(10);
        paramCombo7->setFrame(true);
        paramLabel1 = new QLabel(ValveDialog);
        paramLabel1->setObjectName(QStringLiteral("paramLabel1"));
        paramLabel1->setGeometry(QRect(20, 70, 71, 16));
        paramLabel8 = new QLabel(ValveDialog);
        paramLabel8->setObjectName(QStringLiteral("paramLabel8"));
        paramLabel8->setGeometry(QRect(300, 170, 71, 16));
        paramLabel3 = new QLabel(ValveDialog);
        paramLabel3->setObjectName(QStringLiteral("paramLabel3"));
        paramLabel3->setGeometry(QRect(210, 70, 61, 16));
        paramCombo2 = new QComboBox(ValveDialog);
        paramCombo2->setObjectName(QStringLiteral("paramCombo2"));
        paramCombo2->setGeometry(QRect(120, 90, 69, 22));
        paramCombo4 = new QComboBox(ValveDialog);
        paramCombo4->setObjectName(QStringLiteral("paramCombo4"));
        paramCombo4->setGeometry(QRect(300, 90, 69, 22));
        paramLabel4 = new QLabel(ValveDialog);
        paramLabel4->setObjectName(QStringLiteral("paramLabel4"));
        paramLabel4->setGeometry(QRect(300, 70, 71, 16));
        paramCombo1 = new QComboBox(ValveDialog);
        paramCombo1->setObjectName(QStringLiteral("paramCombo1"));
        paramCombo1->setGeometry(QRect(20, 90, 69, 22));
        ioCombo2 = new QComboBox(ValveDialog);
        ioCombo2->addItem(QString());
        ioCombo2->addItem(QString());
        ioCombo2->setObjectName(QStringLiteral("ioCombo2"));
        ioCombo2->setGeometry(QRect(20, 140, 69, 22));
        paramLabel2 = new QLabel(ValveDialog);
        paramLabel2->setObjectName(QStringLiteral("paramLabel2"));
        paramLabel2->setGeometry(QRect(120, 70, 71, 16));
        ioCombo1 = new QComboBox(ValveDialog);
        ioCombo1->addItem(QString());
        ioCombo1->addItem(QString());
        ioCombo1->setObjectName(QStringLiteral("ioCombo1"));
        ioCombo1->setGeometry(QRect(20, 40, 69, 22));
        paramCombo8 = new QComboBox(ValveDialog);
        paramCombo8->setObjectName(QStringLiteral("paramCombo8"));
        paramCombo8->setGeometry(QRect(300, 190, 69, 22));
        paramCombo5 = new QComboBox(ValveDialog);
        paramCombo5->setObjectName(QStringLiteral("paramCombo5"));
        paramCombo5->setGeometry(QRect(20, 190, 69, 22));
        label = new QLabel(ValveDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 47, 13));
        paramLabel7 = new QLabel(ValveDialog);
        paramLabel7->setObjectName(QStringLiteral("paramLabel7"));
        paramLabel7->setGeometry(QRect(210, 170, 61, 16));
        paramCombo3 = new QComboBox(ValveDialog);
        paramCombo3->setObjectName(QStringLiteral("paramCombo3"));
        paramCombo3->setEnabled(true);
        paramCombo3->setGeometry(QRect(210, 90, 69, 22));
        paramCombo3->setEditable(false);
        paramCombo3->setMaxVisibleItems(10);
        paramCombo3->setFrame(true);
        paramLabel5 = new QLabel(ValveDialog);
        paramLabel5->setObjectName(QStringLiteral("paramLabel5"));
        paramLabel5->setGeometry(QRect(20, 170, 71, 16));
        paramLabel6 = new QLabel(ValveDialog);
        paramLabel6->setObjectName(QStringLiteral("paramLabel6"));
        paramLabel6->setGeometry(QRect(120, 170, 71, 16));
        ioCountSpin2 = new QSpinBox(ValveDialog);
        ioCountSpin2->setObjectName(QStringLiteral("ioCountSpin2"));
        ioCountSpin2->setGeometry(QRect(110, 140, 42, 22));
        ioCountSpin2->setMaximum(4);
        label_31 = new QLabel(ValveDialog);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(110, 120, 47, 13));
        label_27 = new QLabel(ValveDialog);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(110, 20, 47, 13));
        ioCountSpin1 = new QSpinBox(ValveDialog);
        ioCountSpin1->setObjectName(QStringLiteral("ioCountSpin1"));
        ioCountSpin1->setGeometry(QRect(110, 40, 42, 22));
        ioCountSpin1->setMaximum(4);

        retranslateUi(ValveDialog);
        QObject::connect(addBtn, SIGNAL(clicked()), ValveDialog, SLOT(actionAddClicked()));
        QObject::connect(cancelBtn, SIGNAL(clicked()), ValveDialog, SLOT(reject()));
        QObject::connect(paramCombo1, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo2, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo3, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo4, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo5, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo6, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo7, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(parameterDropDownAction()));
        QObject::connect(paramCombo8, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(parameterDropDownAction()));
        QObject::connect(ioCombo1, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(ioDropDownAction()));
        QObject::connect(ioCombo2, SIGNAL(currentIndexChanged(int)), ValveDialog, SLOT(ioDropDownAction()));

        QMetaObject::connectSlotsByName(ValveDialog);
    } // setupUi

    void retranslateUi(QDialog *ValveDialog)
    {
        ValveDialog->setWindowTitle(QApplication::translate("ValveDialog", "Dialog", nullptr));
        addBtn->setText(QApplication::translate("ValveDialog", "Add", nullptr));
        cancelBtn->setText(QApplication::translate("ValveDialog", "Cancel", nullptr));
        label_16->setText(QApplication::translate("ValveDialog", "I/O Type", nullptr));
        paramLabel1->setText(QApplication::translate("ValveDialog", "Parameter 1", nullptr));
        paramLabel8->setText(QApplication::translate("ValveDialog", "Parameter 4", nullptr));
        paramLabel3->setText(QApplication::translate("ValveDialog", "Parameter 3", nullptr));
        paramLabel4->setText(QApplication::translate("ValveDialog", "Parameter 4", nullptr));
        ioCombo2->setItemText(0, QApplication::translate("ValveDialog", "I2C", nullptr));
        ioCombo2->setItemText(1, QApplication::translate("ValveDialog", "GPIO", nullptr));

        paramLabel2->setText(QApplication::translate("ValveDialog", "Parameter 2", nullptr));
        ioCombo1->setItemText(0, QApplication::translate("ValveDialog", "I2C", nullptr));
        ioCombo1->setItemText(1, QApplication::translate("ValveDialog", "GPIO", nullptr));

        label->setText(QApplication::translate("ValveDialog", "I/O Type", nullptr));
        paramLabel7->setText(QApplication::translate("ValveDialog", "Parameter 3", nullptr));
        paramLabel5->setText(QApplication::translate("ValveDialog", "Parameter 1", nullptr));
        paramLabel6->setText(QApplication::translate("ValveDialog", "Parameter 2", nullptr));
        label_31->setText(QApplication::translate("ValveDialog", "IO Count", nullptr));
        label_27->setText(QApplication::translate("ValveDialog", "IO Count", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ValveDialog: public Ui_ValveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALVEDIALOG_H
