/********************************************************************************
** Form generated from reading UI file 'ConfigDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QTabWidget *configTabWidget;
    QWidget *locationTab;
    QLabel *ipLabel;
    QLineEdit *ipField;
    QLabel *nameLabel;
    QLineEdit *locationNameField;
    QSpinBox *spinBox;
    QLabel *portLabel;
    QPushButton *addLocBtn;
    QListWidget *locationList;
    QCheckBox *mnsCheckBox;
    QWidget *managersTab;
    QListWidget *mangerList;
    QComboBox *managerBox;
    QComboBox *locationBox;
    QPushButton *addManagerBtn;
    QLabel *managerLabel;
    QLabel *locationLabel;
    QWidget *machineTab;
    QPushButton *axisAddBtn;
    QPushButton *pumpAddBtn;
    QPushButton *valveAddBtn;
    QListWidget *machineList;
    QTextBrowser *xmlBrowser;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(813, 300);
        saveButton = new QPushButton(ConfigDialog);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(720, 270, 75, 23));
        cancelButton = new QPushButton(ConfigDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(720, 240, 75, 23));
        configTabWidget = new QTabWidget(ConfigDialog);
        configTabWidget->setObjectName(QStringLiteral("configTabWidget"));
        configTabWidget->setGeometry(QRect(10, 10, 311, 281));
        locationTab = new QWidget();
        locationTab->setObjectName(QStringLiteral("locationTab"));
        ipLabel = new QLabel(locationTab);
        ipLabel->setObjectName(QStringLiteral("ipLabel"));
        ipLabel->setGeometry(QRect(20, 30, 61, 21));
        ipField = new QLineEdit(locationTab);
        ipField->setObjectName(QStringLiteral("ipField"));
        ipField->setGeometry(QRect(80, 30, 113, 20));
        nameLabel = new QLabel(locationTab);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(20, 10, 47, 13));
        locationNameField = new QLineEdit(locationTab);
        locationNameField->setObjectName(QStringLiteral("locationNameField"));
        locationNameField->setGeometry(QRect(80, 10, 113, 20));
        spinBox = new QSpinBox(locationTab);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(80, 50, 111, 22));
        portLabel = new QLabel(locationTab);
        portLabel->setObjectName(QStringLiteral("portLabel"));
        portLabel->setGeometry(QRect(20, 60, 47, 13));
        addLocBtn = new QPushButton(locationTab);
        addLocBtn->setObjectName(QStringLiteral("addLocBtn"));
        addLocBtn->setGeometry(QRect(210, 50, 75, 23));
        locationList = new QListWidget(locationTab);
        locationList->setObjectName(QStringLiteral("locationList"));
        locationList->setGeometry(QRect(10, 80, 271, 161));
        mnsCheckBox = new QCheckBox(locationTab);
        mnsCheckBox->setObjectName(QStringLiteral("mnsCheckBox"));
        mnsCheckBox->setGeometry(QRect(210, 10, 70, 17));
        configTabWidget->addTab(locationTab, QString());
        managersTab = new QWidget();
        managersTab->setObjectName(QStringLiteral("managersTab"));
        mangerList = new QListWidget(managersTab);
        mangerList->setObjectName(QStringLiteral("mangerList"));
        mangerList->setGeometry(QRect(0, 60, 256, 192));
        managerBox = new QComboBox(managersTab);
        managerBox->setObjectName(QStringLiteral("managerBox"));
        managerBox->setGeometry(QRect(130, 30, 69, 22));
        locationBox = new QComboBox(managersTab);
        locationBox->setObjectName(QStringLiteral("locationBox"));
        locationBox->setGeometry(QRect(130, 10, 69, 22));
        addManagerBtn = new QPushButton(managersTab);
        addManagerBtn->setObjectName(QStringLiteral("addManagerBtn"));
        addManagerBtn->setGeometry(QRect(210, 10, 75, 23));
        managerLabel = new QLabel(managersTab);
        managerLabel->setObjectName(QStringLiteral("managerLabel"));
        managerLabel->setGeometry(QRect(80, 10, 47, 13));
        locationLabel = new QLabel(managersTab);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));
        locationLabel->setGeometry(QRect(80, 30, 47, 13));
        configTabWidget->addTab(managersTab, QString());
        machineTab = new QWidget();
        machineTab->setObjectName(QStringLiteral("machineTab"));
        axisAddBtn = new QPushButton(machineTab);
        axisAddBtn->setObjectName(QStringLiteral("axisAddBtn"));
        axisAddBtn->setGeometry(QRect(10, 20, 75, 23));
        pumpAddBtn = new QPushButton(machineTab);
        pumpAddBtn->setObjectName(QStringLiteral("pumpAddBtn"));
        pumpAddBtn->setGeometry(QRect(170, 20, 75, 23));
        valveAddBtn = new QPushButton(machineTab);
        valveAddBtn->setObjectName(QStringLiteral("valveAddBtn"));
        valveAddBtn->setGeometry(QRect(90, 20, 75, 23));
        machineList = new QListWidget(machineTab);
        machineList->setObjectName(QStringLiteral("machineList"));
        machineList->setGeometry(QRect(10, 60, 256, 192));
        configTabWidget->addTab(machineTab, QString());
        xmlBrowser = new QTextBrowser(ConfigDialog);
        xmlBrowser->setObjectName(QStringLiteral("xmlBrowser"));
        xmlBrowser->setGeometry(QRect(320, 30, 381, 261));

        retranslateUi(ConfigDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), ConfigDialog, SLOT(reject()));
        QObject::connect(saveButton, SIGNAL(clicked()), ConfigDialog, SLOT(actionSaveClicked()));
        QObject::connect(addLocBtn, SIGNAL(clicked()), ConfigDialog, SLOT(actionAddLocClicked()));
        QObject::connect(addManagerBtn, SIGNAL(clicked()), ConfigDialog, SLOT(actionAddMgrClicked()));
        QObject::connect(axisAddBtn, SIGNAL(clicked()), ConfigDialog, SLOT(actionAddAxisClicked()));
        QObject::connect(valveAddBtn, SIGNAL(clicked()), ConfigDialog, SLOT(actionAddValveClicked()));
        QObject::connect(pumpAddBtn, SIGNAL(clicked()), ConfigDialog, SLOT(actionAddPumpClicked()));

        configTabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Dialog", nullptr));
        saveButton->setText(QApplication::translate("ConfigDialog", "Save", nullptr));
        cancelButton->setText(QApplication::translate("ConfigDialog", "Cancel", nullptr));
        ipLabel->setText(QApplication::translate("ConfigDialog", "IP Address", nullptr));
        nameLabel->setText(QApplication::translate("ConfigDialog", "Name", nullptr));
        portLabel->setText(QApplication::translate("ConfigDialog", "Port", nullptr));
        addLocBtn->setText(QApplication::translate("ConfigDialog", "Add Location", nullptr));
        mnsCheckBox->setText(QApplication::translate("ConfigDialog", "MNS?", nullptr));
        configTabWidget->setTabText(configTabWidget->indexOf(locationTab), QApplication::translate("ConfigDialog", "Locations", nullptr));
        addManagerBtn->setText(QApplication::translate("ConfigDialog", "Add Manager", nullptr));
        managerLabel->setText(QApplication::translate("ConfigDialog", "Manager", nullptr));
        locationLabel->setText(QApplication::translate("ConfigDialog", "Location", nullptr));
        configTabWidget->setTabText(configTabWidget->indexOf(managersTab), QApplication::translate("ConfigDialog", "Managers", nullptr));
        axisAddBtn->setText(QApplication::translate("ConfigDialog", "Add Axis", nullptr));
        pumpAddBtn->setText(QApplication::translate("ConfigDialog", "Add Pump", nullptr));
        valveAddBtn->setText(QApplication::translate("ConfigDialog", "Add Valve", nullptr));
        configTabWidget->setTabText(configTabWidget->indexOf(machineTab), QApplication::translate("ConfigDialog", "Machine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
