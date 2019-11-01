/********************************************************************************
** Form generated from reading UI file 'AxisDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXISDIALOG_H
#define UI_AXISDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AxisDialog
{
public:
    QPushButton *addBtn;
    QPushButton *cancelBtn;
    QComboBox *stepperOneIoComboBox;
    QComboBox *stepper1ioParam1ComboBox1;
    QComboBox *stepper1ioParam2ComboBox1;
    QLabel *stepIOLabelP0;
    QLabel *stepIOLabelP1;
    QLabel *stepIOLabelP2;
    QDoubleSpinBox *axisLenSpin;
    QSpinBox *stepperCntSpin;
    QLabel *label_6;
    QComboBox *axisNameBox;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *limitIOTypeBox;
    QComboBox *limitParam1Box;
    QComboBox *limitParam2Box;
    QLabel *stepIOLabelP30;
    QLabel *stepIOLabelP31;
    QLabel *stepIOLabelP32;
    QLabel *stepIOLabelP3;
    QLabel *stepIOLabelP4;
    QComboBox *stepper1ioParam4ComboBox1;
    QComboBox *stepper1ioParam3ComboBox1;
    QLabel *stepIOLabelP5;
    QComboBox *stepperOneIoComboBox2;
    QLabel *stepIOLabelP9;
    QComboBox *stepper1ioParam4ComboBox2;
    QLabel *stepIOLabelP6;
    QComboBox *stepper1ioParam1ComboBox2;
    QComboBox *stepper1ioParam2ComboBox2;
    QLabel *stepIOLabelP7;
    QComboBox *stepper1ioParam3ComboBox2;
    QLabel *stepIOLabelP8;
    QComboBox *stepper2ioParam2ComboBox1;
    QLabel *stepIOLabelP15;
    QComboBox *stepper2ioParam3ComboBox1;
    QLabel *stepIOLabelP11;
    QLabel *stepIOLabelP19;
    QLabel *stepIOLabelP13;
    QComboBox *stepper1ioParam2ComboBox3;
    QComboBox *stepper1ioParam4ComboBox3;
    QLabel *stepIOLabelP14;
    QComboBox *stepper1ioParam1ComboBox3;
    QComboBox *stepperTwoIoComboBox;
    QLabel *stepIOLabelP12;
    QComboBox *stepperOneIoComboBox3;
    QComboBox *stepper2ioParam4ComboBox1;
    QComboBox *stepper2ioParam1ComboBox1;
    QLabel *stepIOLabelP10;
    QLabel *stepIOLabelP18;
    QComboBox *stepper1ioParam3ComboBox3;
    QLabel *stepIOLabelP16;
    QLabel *stepIOLabelP17;
    QSpinBox *ioCntSpin1;
    QLabel *label_27;
    QComboBox *signalCombo1;
    QComboBox *signalCombo2;
    QComboBox *signalCombo3;
    QComboBox *signalCombo4;
    QLabel *stepIOLabelP20;
    QLabel *stepIOLabelP23;
    QLabel *stepIOLabelP28;
    QComboBox *stepper2ioParam1ComboBox3;
    QLabel *stepIOLabelP25;
    QLabel *stepIOLabelP27;
    QComboBox *stepper2ioParam3ComboBox3;
    QLabel *stepIOLabelP26;
    QComboBox *stepperTwoIoComboBox2;
    QComboBox *stepper2ioParam2ComboBox2;
    QComboBox *stepperTwoIoComboBox3;
    QLabel *stepIOLabelP29;
    QLabel *stepIOLabelP24;
    QComboBox *stepper2ioParam2ComboBox3;
    QComboBox *stepper2ioParam4ComboBox2;
    QComboBox *signalCombo6;
    QLabel *stepIOLabelP21;
    QLabel *stepIOLabelP22;
    QComboBox *stepper2ioParam3ComboBox2;
    QComboBox *signalCombo5;
    QComboBox *stepper2ioParam4ComboBox3;
    QComboBox *stepper2ioParam1ComboBox2;
    QLabel *stepIOLabelP33;
    QComboBox *limitParam3Box;
    QComboBox *limitParam4Box;
    QLabel *stepIOLabelP34;
    QComboBox *signalCombo7;

    void setupUi(QDialog *AxisDialog)
    {
        if (AxisDialog->objectName().isEmpty())
            AxisDialog->setObjectName(QStringLiteral("AxisDialog"));
        AxisDialog->resize(446, 810);
        addBtn = new QPushButton(AxisDialog);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setEnabled(false);
        addBtn->setGeometry(QRect(350, 730, 75, 23));
        cancelBtn = new QPushButton(AxisDialog);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(350, 770, 75, 23));
        stepperOneIoComboBox = new QComboBox(AxisDialog);
        stepperOneIoComboBox->addItem(QString());
        stepperOneIoComboBox->addItem(QString());
        stepperOneIoComboBox->setObjectName(QStringLiteral("stepperOneIoComboBox"));
        stepperOneIoComboBox->setGeometry(QRect(70, 30, 69, 22));
        stepper1ioParam1ComboBox1 = new QComboBox(AxisDialog);
        stepper1ioParam1ComboBox1->setObjectName(QStringLiteral("stepper1ioParam1ComboBox1"));
        stepper1ioParam1ComboBox1->setGeometry(QRect(70, 80, 69, 22));
        stepper1ioParam1ComboBox1->setEditable(true);
        stepper1ioParam2ComboBox1 = new QComboBox(AxisDialog);
        stepper1ioParam2ComboBox1->setObjectName(QStringLiteral("stepper1ioParam2ComboBox1"));
        stepper1ioParam2ComboBox1->setGeometry(QRect(170, 80, 69, 22));
        stepper1ioParam2ComboBox1->setEditable(true);
        stepIOLabelP0 = new QLabel(AxisDialog);
        stepIOLabelP0->setObjectName(QStringLiteral("stepIOLabelP0"));
        stepIOLabelP0->setGeometry(QRect(70, 10, 47, 13));
        stepIOLabelP1 = new QLabel(AxisDialog);
        stepIOLabelP1->setObjectName(QStringLiteral("stepIOLabelP1"));
        stepIOLabelP1->setGeometry(QRect(70, 60, 71, 16));
        stepIOLabelP2 = new QLabel(AxisDialog);
        stepIOLabelP2->setObjectName(QStringLiteral("stepIOLabelP2"));
        stepIOLabelP2->setGeometry(QRect(170, 60, 71, 16));
        axisLenSpin = new QDoubleSpinBox(AxisDialog);
        axisLenSpin->setObjectName(QStringLiteral("axisLenSpin"));
        axisLenSpin->setGeometry(QRect(350, 640, 62, 22));
        stepperCntSpin = new QSpinBox(AxisDialog);
        stepperCntSpin->setObjectName(QStringLiteral("stepperCntSpin"));
        stepperCntSpin->setGeometry(QRect(220, 30, 42, 22));
        stepperCntSpin->setMinimum(1);
        stepperCntSpin->setMaximum(2);
        label_6 = new QLabel(AxisDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 620, 91, 16));
        axisNameBox = new QComboBox(AxisDialog);
        axisNameBox->setObjectName(QStringLiteral("axisNameBox"));
        axisNameBox->setGeometry(QRect(310, 30, 69, 22));
        axisNameBox->setEditable(true);
        label_7 = new QLabel(AxisDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(310, 10, 71, 16));
        label_8 = new QLabel(AxisDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(210, 10, 81, 16));
        limitIOTypeBox = new QComboBox(AxisDialog);
        limitIOTypeBox->addItem(QString());
        limitIOTypeBox->addItem(QString());
        limitIOTypeBox->setObjectName(QStringLiteral("limitIOTypeBox"));
        limitIOTypeBox->setGeometry(QRect(70, 640, 69, 22));
        limitParam1Box = new QComboBox(AxisDialog);
        limitParam1Box->setObjectName(QStringLiteral("limitParam1Box"));
        limitParam1Box->setGeometry(QRect(70, 690, 69, 22));
        limitParam1Box->setEditable(true);
        limitParam2Box = new QComboBox(AxisDialog);
        limitParam2Box->setObjectName(QStringLiteral("limitParam2Box"));
        limitParam2Box->setGeometry(QRect(170, 690, 69, 22));
        limitParam2Box->setEditable(true);
        stepIOLabelP30 = new QLabel(AxisDialog);
        stepIOLabelP30->setObjectName(QStringLiteral("stepIOLabelP30"));
        stepIOLabelP30->setGeometry(QRect(70, 620, 47, 13));
        stepIOLabelP31 = new QLabel(AxisDialog);
        stepIOLabelP31->setObjectName(QStringLiteral("stepIOLabelP31"));
        stepIOLabelP31->setGeometry(QRect(70, 670, 71, 16));
        stepIOLabelP32 = new QLabel(AxisDialog);
        stepIOLabelP32->setObjectName(QStringLiteral("stepIOLabelP32"));
        stepIOLabelP32->setGeometry(QRect(170, 670, 71, 16));
        stepIOLabelP3 = new QLabel(AxisDialog);
        stepIOLabelP3->setObjectName(QStringLiteral("stepIOLabelP3"));
        stepIOLabelP3->setGeometry(QRect(260, 60, 61, 16));
        stepIOLabelP4 = new QLabel(AxisDialog);
        stepIOLabelP4->setObjectName(QStringLiteral("stepIOLabelP4"));
        stepIOLabelP4->setGeometry(QRect(350, 60, 71, 16));
        stepper1ioParam4ComboBox1 = new QComboBox(AxisDialog);
        stepper1ioParam4ComboBox1->setObjectName(QStringLiteral("stepper1ioParam4ComboBox1"));
        stepper1ioParam4ComboBox1->setGeometry(QRect(350, 80, 69, 22));
        stepper1ioParam4ComboBox1->setEditable(true);
        stepper1ioParam3ComboBox1 = new QComboBox(AxisDialog);
        stepper1ioParam3ComboBox1->setObjectName(QStringLiteral("stepper1ioParam3ComboBox1"));
        stepper1ioParam3ComboBox1->setEnabled(true);
        stepper1ioParam3ComboBox1->setGeometry(QRect(260, 80, 69, 22));
        stepper1ioParam3ComboBox1->setEditable(true);
        stepper1ioParam3ComboBox1->setMaxVisibleItems(10);
        stepper1ioParam3ComboBox1->setFrame(true);
        stepIOLabelP5 = new QLabel(AxisDialog);
        stepIOLabelP5->setObjectName(QStringLiteral("stepIOLabelP5"));
        stepIOLabelP5->setGeometry(QRect(70, 110, 47, 13));
        stepperOneIoComboBox2 = new QComboBox(AxisDialog);
        stepperOneIoComboBox2->addItem(QString());
        stepperOneIoComboBox2->addItem(QString());
        stepperOneIoComboBox2->setObjectName(QStringLiteral("stepperOneIoComboBox2"));
        stepperOneIoComboBox2->setGeometry(QRect(70, 130, 69, 22));
        stepIOLabelP9 = new QLabel(AxisDialog);
        stepIOLabelP9->setObjectName(QStringLiteral("stepIOLabelP9"));
        stepIOLabelP9->setGeometry(QRect(350, 160, 71, 16));
        stepper1ioParam4ComboBox2 = new QComboBox(AxisDialog);
        stepper1ioParam4ComboBox2->setObjectName(QStringLiteral("stepper1ioParam4ComboBox2"));
        stepper1ioParam4ComboBox2->setGeometry(QRect(350, 180, 69, 22));
        stepper1ioParam4ComboBox2->setEditable(true);
        stepIOLabelP6 = new QLabel(AxisDialog);
        stepIOLabelP6->setObjectName(QStringLiteral("stepIOLabelP6"));
        stepIOLabelP6->setGeometry(QRect(70, 160, 71, 16));
        stepper1ioParam1ComboBox2 = new QComboBox(AxisDialog);
        stepper1ioParam1ComboBox2->setObjectName(QStringLiteral("stepper1ioParam1ComboBox2"));
        stepper1ioParam1ComboBox2->setGeometry(QRect(70, 180, 69, 22));
        stepper1ioParam1ComboBox2->setEditable(true);
        stepper1ioParam2ComboBox2 = new QComboBox(AxisDialog);
        stepper1ioParam2ComboBox2->setObjectName(QStringLiteral("stepper1ioParam2ComboBox2"));
        stepper1ioParam2ComboBox2->setGeometry(QRect(170, 180, 69, 22));
        stepper1ioParam2ComboBox2->setEditable(true);
        stepIOLabelP7 = new QLabel(AxisDialog);
        stepIOLabelP7->setObjectName(QStringLiteral("stepIOLabelP7"));
        stepIOLabelP7->setGeometry(QRect(170, 160, 71, 16));
        stepper1ioParam3ComboBox2 = new QComboBox(AxisDialog);
        stepper1ioParam3ComboBox2->setObjectName(QStringLiteral("stepper1ioParam3ComboBox2"));
        stepper1ioParam3ComboBox2->setEnabled(true);
        stepper1ioParam3ComboBox2->setGeometry(QRect(260, 180, 69, 22));
        stepper1ioParam3ComboBox2->setEditable(true);
        stepper1ioParam3ComboBox2->setMaxVisibleItems(10);
        stepper1ioParam3ComboBox2->setFrame(true);
        stepIOLabelP8 = new QLabel(AxisDialog);
        stepIOLabelP8->setObjectName(QStringLiteral("stepIOLabelP8"));
        stepIOLabelP8->setGeometry(QRect(260, 160, 61, 16));
        stepper2ioParam2ComboBox1 = new QComboBox(AxisDialog);
        stepper2ioParam2ComboBox1->setObjectName(QStringLiteral("stepper2ioParam2ComboBox1"));
        stepper2ioParam2ComboBox1->setGeometry(QRect(170, 390, 69, 22));
        stepper2ioParam2ComboBox1->setEditable(true);
        stepIOLabelP15 = new QLabel(AxisDialog);
        stepIOLabelP15->setObjectName(QStringLiteral("stepIOLabelP15"));
        stepIOLabelP15->setGeometry(QRect(70, 320, 47, 13));
        stepper2ioParam3ComboBox1 = new QComboBox(AxisDialog);
        stepper2ioParam3ComboBox1->setObjectName(QStringLiteral("stepper2ioParam3ComboBox1"));
        stepper2ioParam3ComboBox1->setEnabled(true);
        stepper2ioParam3ComboBox1->setGeometry(QRect(260, 390, 69, 22));
        stepper2ioParam3ComboBox1->setEditable(true);
        stepper2ioParam3ComboBox1->setMaxVisibleItems(10);
        stepper2ioParam3ComboBox1->setFrame(true);
        stepIOLabelP11 = new QLabel(AxisDialog);
        stepIOLabelP11->setObjectName(QStringLiteral("stepIOLabelP11"));
        stepIOLabelP11->setGeometry(QRect(70, 270, 71, 16));
        stepIOLabelP19 = new QLabel(AxisDialog);
        stepIOLabelP19->setObjectName(QStringLiteral("stepIOLabelP19"));
        stepIOLabelP19->setGeometry(QRect(350, 370, 71, 16));
        stepIOLabelP13 = new QLabel(AxisDialog);
        stepIOLabelP13->setObjectName(QStringLiteral("stepIOLabelP13"));
        stepIOLabelP13->setGeometry(QRect(260, 270, 61, 16));
        stepper1ioParam2ComboBox3 = new QComboBox(AxisDialog);
        stepper1ioParam2ComboBox3->setObjectName(QStringLiteral("stepper1ioParam2ComboBox3"));
        stepper1ioParam2ComboBox3->setGeometry(QRect(170, 290, 69, 22));
        stepper1ioParam2ComboBox3->setEditable(true);
        stepper1ioParam4ComboBox3 = new QComboBox(AxisDialog);
        stepper1ioParam4ComboBox3->setObjectName(QStringLiteral("stepper1ioParam4ComboBox3"));
        stepper1ioParam4ComboBox3->setGeometry(QRect(350, 290, 69, 22));
        stepper1ioParam4ComboBox3->setEditable(true);
        stepIOLabelP14 = new QLabel(AxisDialog);
        stepIOLabelP14->setObjectName(QStringLiteral("stepIOLabelP14"));
        stepIOLabelP14->setGeometry(QRect(350, 270, 71, 16));
        stepper1ioParam1ComboBox3 = new QComboBox(AxisDialog);
        stepper1ioParam1ComboBox3->setObjectName(QStringLiteral("stepper1ioParam1ComboBox3"));
        stepper1ioParam1ComboBox3->setGeometry(QRect(70, 290, 69, 22));
        stepper1ioParam1ComboBox3->setEditable(true);
        stepperTwoIoComboBox = new QComboBox(AxisDialog);
        stepperTwoIoComboBox->addItem(QString());
        stepperTwoIoComboBox->addItem(QString());
        stepperTwoIoComboBox->setObjectName(QStringLiteral("stepperTwoIoComboBox"));
        stepperTwoIoComboBox->setGeometry(QRect(70, 340, 69, 22));
        stepIOLabelP12 = new QLabel(AxisDialog);
        stepIOLabelP12->setObjectName(QStringLiteral("stepIOLabelP12"));
        stepIOLabelP12->setGeometry(QRect(170, 270, 71, 16));
        stepperOneIoComboBox3 = new QComboBox(AxisDialog);
        stepperOneIoComboBox3->addItem(QString());
        stepperOneIoComboBox3->addItem(QString());
        stepperOneIoComboBox3->setObjectName(QStringLiteral("stepperOneIoComboBox3"));
        stepperOneIoComboBox3->setGeometry(QRect(70, 240, 69, 22));
        stepper2ioParam4ComboBox1 = new QComboBox(AxisDialog);
        stepper2ioParam4ComboBox1->setObjectName(QStringLiteral("stepper2ioParam4ComboBox1"));
        stepper2ioParam4ComboBox1->setGeometry(QRect(350, 390, 69, 22));
        stepper2ioParam4ComboBox1->setEditable(true);
        stepper2ioParam1ComboBox1 = new QComboBox(AxisDialog);
        stepper2ioParam1ComboBox1->setObjectName(QStringLiteral("stepper2ioParam1ComboBox1"));
        stepper2ioParam1ComboBox1->setGeometry(QRect(70, 390, 69, 22));
        stepper2ioParam1ComboBox1->setEditable(true);
        stepIOLabelP10 = new QLabel(AxisDialog);
        stepIOLabelP10->setObjectName(QStringLiteral("stepIOLabelP10"));
        stepIOLabelP10->setGeometry(QRect(70, 220, 47, 13));
        stepIOLabelP18 = new QLabel(AxisDialog);
        stepIOLabelP18->setObjectName(QStringLiteral("stepIOLabelP18"));
        stepIOLabelP18->setGeometry(QRect(260, 370, 61, 16));
        stepper1ioParam3ComboBox3 = new QComboBox(AxisDialog);
        stepper1ioParam3ComboBox3->setObjectName(QStringLiteral("stepper1ioParam3ComboBox3"));
        stepper1ioParam3ComboBox3->setEnabled(true);
        stepper1ioParam3ComboBox3->setGeometry(QRect(260, 290, 69, 22));
        stepper1ioParam3ComboBox3->setEditable(true);
        stepper1ioParam3ComboBox3->setMaxVisibleItems(10);
        stepper1ioParam3ComboBox3->setFrame(true);
        stepIOLabelP16 = new QLabel(AxisDialog);
        stepIOLabelP16->setObjectName(QStringLiteral("stepIOLabelP16"));
        stepIOLabelP16->setGeometry(QRect(70, 370, 71, 16));
        stepIOLabelP17 = new QLabel(AxisDialog);
        stepIOLabelP17->setObjectName(QStringLiteral("stepIOLabelP17"));
        stepIOLabelP17->setGeometry(QRect(170, 370, 71, 16));
        ioCntSpin1 = new QSpinBox(AxisDialog);
        ioCntSpin1->setObjectName(QStringLiteral("ioCntSpin1"));
        ioCntSpin1->setGeometry(QRect(150, 30, 42, 22));
        ioCntSpin1->setMaximum(7);
        label_27 = new QLabel(AxisDialog);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(150, 10, 47, 13));
        signalCombo1 = new QComboBox(AxisDialog);
        signalCombo1->addItem(QString());
        signalCombo1->addItem(QString());
        signalCombo1->addItem(QString());
        signalCombo1->setObjectName(QStringLiteral("signalCombo1"));
        signalCombo1->setGeometry(QRect(10, 80, 41, 22));
        signalCombo2 = new QComboBox(AxisDialog);
        signalCombo2->addItem(QString());
        signalCombo2->setObjectName(QStringLiteral("signalCombo2"));
        signalCombo2->setGeometry(QRect(10, 180, 41, 22));
        signalCombo3 = new QComboBox(AxisDialog);
        signalCombo3->addItem(QString());
        signalCombo3->setObjectName(QStringLiteral("signalCombo3"));
        signalCombo3->setGeometry(QRect(10, 290, 41, 22));
        signalCombo4 = new QComboBox(AxisDialog);
        signalCombo4->addItem(QString());
        signalCombo4->addItem(QString());
        signalCombo4->addItem(QString());
        signalCombo4->setObjectName(QStringLiteral("signalCombo4"));
        signalCombo4->setGeometry(QRect(10, 390, 41, 22));
        stepIOLabelP20 = new QLabel(AxisDialog);
        stepIOLabelP20->setObjectName(QStringLiteral("stepIOLabelP20"));
        stepIOLabelP20->setGeometry(QRect(70, 420, 47, 13));
        stepIOLabelP23 = new QLabel(AxisDialog);
        stepIOLabelP23->setObjectName(QStringLiteral("stepIOLabelP23"));
        stepIOLabelP23->setGeometry(QRect(260, 470, 61, 16));
        stepIOLabelP28 = new QLabel(AxisDialog);
        stepIOLabelP28->setObjectName(QStringLiteral("stepIOLabelP28"));
        stepIOLabelP28->setGeometry(QRect(260, 570, 61, 16));
        stepper2ioParam1ComboBox3 = new QComboBox(AxisDialog);
        stepper2ioParam1ComboBox3->setObjectName(QStringLiteral("stepper2ioParam1ComboBox3"));
        stepper2ioParam1ComboBox3->setGeometry(QRect(70, 590, 69, 22));
        stepper2ioParam1ComboBox3->setEditable(true);
        stepIOLabelP25 = new QLabel(AxisDialog);
        stepIOLabelP25->setObjectName(QStringLiteral("stepIOLabelP25"));
        stepIOLabelP25->setGeometry(QRect(70, 520, 47, 13));
        stepIOLabelP27 = new QLabel(AxisDialog);
        stepIOLabelP27->setObjectName(QStringLiteral("stepIOLabelP27"));
        stepIOLabelP27->setGeometry(QRect(170, 570, 71, 16));
        stepper2ioParam3ComboBox3 = new QComboBox(AxisDialog);
        stepper2ioParam3ComboBox3->setObjectName(QStringLiteral("stepper2ioParam3ComboBox3"));
        stepper2ioParam3ComboBox3->setEnabled(true);
        stepper2ioParam3ComboBox3->setGeometry(QRect(260, 590, 69, 22));
        stepper2ioParam3ComboBox3->setEditable(true);
        stepper2ioParam3ComboBox3->setMaxVisibleItems(10);
        stepper2ioParam3ComboBox3->setFrame(true);
        stepIOLabelP26 = new QLabel(AxisDialog);
        stepIOLabelP26->setObjectName(QStringLiteral("stepIOLabelP26"));
        stepIOLabelP26->setGeometry(QRect(70, 570, 71, 16));
        stepperTwoIoComboBox2 = new QComboBox(AxisDialog);
        stepperTwoIoComboBox2->addItem(QString());
        stepperTwoIoComboBox2->addItem(QString());
        stepperTwoIoComboBox2->setObjectName(QStringLiteral("stepperTwoIoComboBox2"));
        stepperTwoIoComboBox2->setGeometry(QRect(70, 440, 69, 22));
        stepper2ioParam2ComboBox2 = new QComboBox(AxisDialog);
        stepper2ioParam2ComboBox2->setObjectName(QStringLiteral("stepper2ioParam2ComboBox2"));
        stepper2ioParam2ComboBox2->setGeometry(QRect(170, 490, 69, 22));
        stepper2ioParam2ComboBox2->setEditable(true);
        stepperTwoIoComboBox3 = new QComboBox(AxisDialog);
        stepperTwoIoComboBox3->addItem(QString());
        stepperTwoIoComboBox3->addItem(QString());
        stepperTwoIoComboBox3->setObjectName(QStringLiteral("stepperTwoIoComboBox3"));
        stepperTwoIoComboBox3->setGeometry(QRect(70, 540, 69, 22));
        stepIOLabelP29 = new QLabel(AxisDialog);
        stepIOLabelP29->setObjectName(QStringLiteral("stepIOLabelP29"));
        stepIOLabelP29->setGeometry(QRect(350, 570, 71, 16));
        stepIOLabelP24 = new QLabel(AxisDialog);
        stepIOLabelP24->setObjectName(QStringLiteral("stepIOLabelP24"));
        stepIOLabelP24->setGeometry(QRect(350, 470, 71, 16));
        stepper2ioParam2ComboBox3 = new QComboBox(AxisDialog);
        stepper2ioParam2ComboBox3->setObjectName(QStringLiteral("stepper2ioParam2ComboBox3"));
        stepper2ioParam2ComboBox3->setGeometry(QRect(170, 590, 69, 22));
        stepper2ioParam2ComboBox3->setEditable(true);
        stepper2ioParam4ComboBox2 = new QComboBox(AxisDialog);
        stepper2ioParam4ComboBox2->setObjectName(QStringLiteral("stepper2ioParam4ComboBox2"));
        stepper2ioParam4ComboBox2->setGeometry(QRect(350, 490, 69, 22));
        stepper2ioParam4ComboBox2->setEditable(true);
        signalCombo6 = new QComboBox(AxisDialog);
        signalCombo6->addItem(QString());
        signalCombo6->setObjectName(QStringLiteral("signalCombo6"));
        signalCombo6->setGeometry(QRect(10, 590, 41, 22));
        stepIOLabelP21 = new QLabel(AxisDialog);
        stepIOLabelP21->setObjectName(QStringLiteral("stepIOLabelP21"));
        stepIOLabelP21->setGeometry(QRect(70, 470, 71, 16));
        stepIOLabelP22 = new QLabel(AxisDialog);
        stepIOLabelP22->setObjectName(QStringLiteral("stepIOLabelP22"));
        stepIOLabelP22->setGeometry(QRect(170, 470, 71, 16));
        stepper2ioParam3ComboBox2 = new QComboBox(AxisDialog);
        stepper2ioParam3ComboBox2->setObjectName(QStringLiteral("stepper2ioParam3ComboBox2"));
        stepper2ioParam3ComboBox2->setEnabled(true);
        stepper2ioParam3ComboBox2->setGeometry(QRect(260, 490, 69, 22));
        stepper2ioParam3ComboBox2->setEditable(true);
        stepper2ioParam3ComboBox2->setMaxVisibleItems(10);
        stepper2ioParam3ComboBox2->setFrame(true);
        signalCombo5 = new QComboBox(AxisDialog);
        signalCombo5->addItem(QString());
        signalCombo5->setObjectName(QStringLiteral("signalCombo5"));
        signalCombo5->setGeometry(QRect(10, 490, 41, 22));
        stepper2ioParam4ComboBox3 = new QComboBox(AxisDialog);
        stepper2ioParam4ComboBox3->setObjectName(QStringLiteral("stepper2ioParam4ComboBox3"));
        stepper2ioParam4ComboBox3->setGeometry(QRect(350, 590, 69, 22));
        stepper2ioParam4ComboBox3->setEditable(true);
        stepper2ioParam1ComboBox2 = new QComboBox(AxisDialog);
        stepper2ioParam1ComboBox2->setObjectName(QStringLiteral("stepper2ioParam1ComboBox2"));
        stepper2ioParam1ComboBox2->setGeometry(QRect(70, 490, 69, 22));
        stepper2ioParam1ComboBox2->setEditable(true);
        stepIOLabelP33 = new QLabel(AxisDialog);
        stepIOLabelP33->setObjectName(QStringLiteral("stepIOLabelP33"));
        stepIOLabelP33->setGeometry(QRect(260, 670, 61, 16));
        limitParam3Box = new QComboBox(AxisDialog);
        limitParam3Box->setObjectName(QStringLiteral("limitParam3Box"));
        limitParam3Box->setEnabled(true);
        limitParam3Box->setGeometry(QRect(260, 690, 69, 22));
        limitParam3Box->setEditable(true);
        limitParam3Box->setMaxVisibleItems(10);
        limitParam3Box->setFrame(true);
        limitParam4Box = new QComboBox(AxisDialog);
        limitParam4Box->setObjectName(QStringLiteral("limitParam4Box"));
        limitParam4Box->setGeometry(QRect(350, 690, 69, 22));
        limitParam4Box->setEditable(true);
        stepIOLabelP34 = new QLabel(AxisDialog);
        stepIOLabelP34->setObjectName(QStringLiteral("stepIOLabelP34"));
        stepIOLabelP34->setGeometry(QRect(350, 670, 71, 16));
        signalCombo7 = new QComboBox(AxisDialog);
        signalCombo7->addItem(QString());
        signalCombo7->setObjectName(QStringLiteral("signalCombo7"));
        signalCombo7->setGeometry(QRect(10, 690, 41, 22));

        retranslateUi(AxisDialog);
        QObject::connect(addBtn, SIGNAL(clicked()), AxisDialog, SLOT(actionAddClicked()));
        QObject::connect(cancelBtn, SIGNAL(clicked()), AxisDialog, SLOT(reject()));
        QObject::connect(stepperOneIoComboBox, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(ioDropDownAction()));
        QObject::connect(stepperOneIoComboBox2, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(ioDropDownAction()));
        QObject::connect(stepperOneIoComboBox3, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(ioDropDownAction()));
        QObject::connect(stepperTwoIoComboBox, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(ioDropDownAction()));
        QObject::connect(limitIOTypeBox, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(ioDropDownAction()));
        QObject::connect(stepperCntSpin, SIGNAL(valueChanged(int)), AxisDialog, SLOT(stepperSpinAction()));
        QObject::connect(ioCntSpin1, SIGNAL(valueChanged(int)), AxisDialog, SLOT(ioCountSpinAction()));
        QObject::connect(stepper1ioParam1ComboBox1, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam2ComboBox1, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam3ComboBox1, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam4ComboBox1, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam1ComboBox2, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam2ComboBox2, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam3ComboBox2, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam4ComboBox2, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam1ComboBox3, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam2ComboBox3, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam3ComboBox3, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper1ioParam4ComboBox3, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper2ioParam1ComboBox1, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper2ioParam2ComboBox1, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper2ioParam3ComboBox1, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(stepper2ioParam4ComboBox1, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(limitParam1Box, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));
        QObject::connect(limitParam2Box, SIGNAL(currentIndexChanged(int)), AxisDialog, SLOT(parameterDropDownAction()));

        QMetaObject::connectSlotsByName(AxisDialog);
    } // setupUi

    void retranslateUi(QDialog *AxisDialog)
    {
        AxisDialog->setWindowTitle(QApplication::translate("AxisDialog", "Dialog", nullptr));
        addBtn->setText(QApplication::translate("AxisDialog", "Add", nullptr));
        cancelBtn->setText(QApplication::translate("AxisDialog", "Cancel", nullptr));
        stepperOneIoComboBox->setItemText(0, QApplication::translate("AxisDialog", "I2C", nullptr));
        stepperOneIoComboBox->setItemText(1, QApplication::translate("AxisDialog", "GPIO", nullptr));

        stepIOLabelP0->setText(QApplication::translate("AxisDialog", "I/O Type", nullptr));
        stepIOLabelP1->setText(QApplication::translate("AxisDialog", "Parameter 1", nullptr));
        stepIOLabelP2->setText(QApplication::translate("AxisDialog", "Parameter 2", nullptr));
        label_6->setText(QApplication::translate("AxisDialog", "Axis Length (mm)", nullptr));
        label_7->setText(QApplication::translate("AxisDialog", "Axis Name", nullptr));
        label_8->setText(QApplication::translate("AxisDialog", "Stepper Count", nullptr));
        limitIOTypeBox->setItemText(0, QApplication::translate("AxisDialog", "I2C", nullptr));
        limitIOTypeBox->setItemText(1, QApplication::translate("AxisDialog", "GPIO", nullptr));

        stepIOLabelP30->setText(QApplication::translate("AxisDialog", "I/O Type", nullptr));
        stepIOLabelP31->setText(QApplication::translate("AxisDialog", "Parameter 1", nullptr));
        stepIOLabelP32->setText(QApplication::translate("AxisDialog", "Parameter 2", nullptr));
        stepIOLabelP3->setText(QApplication::translate("AxisDialog", "Parameter 3", nullptr));
        stepIOLabelP4->setText(QApplication::translate("AxisDialog", "Parameter 4", nullptr));
        stepIOLabelP5->setText(QApplication::translate("AxisDialog", "I/O Type", nullptr));
        stepperOneIoComboBox2->setItemText(0, QApplication::translate("AxisDialog", "I2C", nullptr));
        stepperOneIoComboBox2->setItemText(1, QApplication::translate("AxisDialog", "GPIO", nullptr));

        stepIOLabelP9->setText(QApplication::translate("AxisDialog", "Parameter 4", nullptr));
        stepIOLabelP6->setText(QApplication::translate("AxisDialog", "Parameter 1", nullptr));
        stepIOLabelP7->setText(QApplication::translate("AxisDialog", "Parameter 2", nullptr));
        stepIOLabelP8->setText(QApplication::translate("AxisDialog", "Parameter 3", nullptr));
        stepIOLabelP15->setText(QApplication::translate("AxisDialog", "I/O Type", nullptr));
        stepIOLabelP11->setText(QApplication::translate("AxisDialog", "Parameter 1", nullptr));
        stepIOLabelP19->setText(QApplication::translate("AxisDialog", "Parameter 4", nullptr));
        stepIOLabelP13->setText(QApplication::translate("AxisDialog", "Parameter 3", nullptr));
        stepIOLabelP14->setText(QApplication::translate("AxisDialog", "Parameter 4", nullptr));
        stepperTwoIoComboBox->setItemText(0, QApplication::translate("AxisDialog", "I2C", nullptr));
        stepperTwoIoComboBox->setItemText(1, QApplication::translate("AxisDialog", "GPIO", nullptr));

        stepIOLabelP12->setText(QApplication::translate("AxisDialog", "Parameter 2", nullptr));
        stepperOneIoComboBox3->setItemText(0, QApplication::translate("AxisDialog", "I2C", nullptr));
        stepperOneIoComboBox3->setItemText(1, QApplication::translate("AxisDialog", "GPIO", nullptr));

        stepIOLabelP10->setText(QApplication::translate("AxisDialog", "I/O Type", nullptr));
        stepIOLabelP18->setText(QApplication::translate("AxisDialog", "Parameter 3", nullptr));
        stepIOLabelP16->setText(QApplication::translate("AxisDialog", "Parameter 1", nullptr));
        stepIOLabelP17->setText(QApplication::translate("AxisDialog", "Parameter 2", nullptr));
        label_27->setText(QApplication::translate("AxisDialog", "IO Count", nullptr));
        signalCombo1->setItemText(0, QApplication::translate("AxisDialog", "PUL", nullptr));
        signalCombo1->setItemText(1, QApplication::translate("AxisDialog", "DIR", nullptr));
        signalCombo1->setItemText(2, QApplication::translate("AxisDialog", "EN", nullptr));

        signalCombo2->setItemText(0, QApplication::translate("AxisDialog", "DIR", nullptr));

        signalCombo3->setItemText(0, QApplication::translate("AxisDialog", "EN", nullptr));

        signalCombo4->setItemText(0, QApplication::translate("AxisDialog", "PUL", nullptr));
        signalCombo4->setItemText(1, QApplication::translate("AxisDialog", "DIR", nullptr));
        signalCombo4->setItemText(2, QApplication::translate("AxisDialog", "EN", nullptr));

        stepIOLabelP20->setText(QApplication::translate("AxisDialog", "I/O Type", nullptr));
        stepIOLabelP23->setText(QApplication::translate("AxisDialog", "Parameter 3", nullptr));
        stepIOLabelP28->setText(QApplication::translate("AxisDialog", "Parameter 3", nullptr));
        stepIOLabelP25->setText(QApplication::translate("AxisDialog", "I/O Type", nullptr));
        stepIOLabelP27->setText(QApplication::translate("AxisDialog", "Parameter 2", nullptr));
        stepIOLabelP26->setText(QApplication::translate("AxisDialog", "Parameter 1", nullptr));
        stepperTwoIoComboBox2->setItemText(0, QApplication::translate("AxisDialog", "I2C", nullptr));
        stepperTwoIoComboBox2->setItemText(1, QApplication::translate("AxisDialog", "GPIO", nullptr));

        stepperTwoIoComboBox3->setItemText(0, QApplication::translate("AxisDialog", "I2C", nullptr));
        stepperTwoIoComboBox3->setItemText(1, QApplication::translate("AxisDialog", "GPIO", nullptr));

        stepIOLabelP29->setText(QApplication::translate("AxisDialog", "Parameter 4", nullptr));
        stepIOLabelP24->setText(QApplication::translate("AxisDialog", "Parameter 4", nullptr));
        signalCombo6->setItemText(0, QApplication::translate("AxisDialog", "EN", nullptr));

        stepIOLabelP21->setText(QApplication::translate("AxisDialog", "Parameter 1", nullptr));
        stepIOLabelP22->setText(QApplication::translate("AxisDialog", "Parameter 2", nullptr));
        signalCombo5->setItemText(0, QApplication::translate("AxisDialog", "DIR", nullptr));

        stepIOLabelP33->setText(QApplication::translate("AxisDialog", "Parameter 3", nullptr));
        stepIOLabelP34->setText(QApplication::translate("AxisDialog", "Parameter 4", nullptr));
        signalCombo7->setItemText(0, QApplication::translate("AxisDialog", "LIM", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AxisDialog: public Ui_AxisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXISDIALOG_H
