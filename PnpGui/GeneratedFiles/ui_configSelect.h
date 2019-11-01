/********************************************************************************
** Form generated from reading UI file 'configSelect.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGSELECT_H
#define UI_CONFIGSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConfigSelect
{
public:
    QPushButton *browseBtn;
    QLineEdit *pathEdit;
    QPushButton *openBtn;
    QPushButton *newBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *ConfigSelect)
    {
        if (ConfigSelect->objectName().isEmpty())
            ConfigSelect->setObjectName(QStringLiteral("ConfigSelect"));
        ConfigSelect->resize(393, 111);
        browseBtn = new QPushButton(ConfigSelect);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(200, 20, 75, 23));
        pathEdit = new QLineEdit(ConfigSelect);
        pathEdit->setObjectName(QStringLiteral("pathEdit"));
        pathEdit->setGeometry(QRect(20, 20, 161, 20));
        openBtn = new QPushButton(ConfigSelect);
        openBtn->setObjectName(QStringLiteral("openBtn"));
        openBtn->setEnabled(false);
        openBtn->setGeometry(QRect(290, 20, 75, 23));
        newBtn = new QPushButton(ConfigSelect);
        newBtn->setObjectName(QStringLiteral("newBtn"));
        newBtn->setGeometry(QRect(200, 50, 75, 23));
        cancelBtn = new QPushButton(ConfigSelect);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(200, 80, 75, 23));

        retranslateUi(ConfigSelect);
        QObject::connect(browseBtn, SIGNAL(clicked()), ConfigSelect, SLOT(actionBrowseClicked()));
        QObject::connect(openBtn, SIGNAL(clicked()), ConfigSelect, SLOT(actionOpenClicked()));
        QObject::connect(newBtn, SIGNAL(clicked()), ConfigSelect, SLOT(actionNewClicked()));
        QObject::connect(cancelBtn, SIGNAL(clicked()), ConfigSelect, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigSelect);
    } // setupUi

    void retranslateUi(QDialog *ConfigSelect)
    {
        ConfigSelect->setWindowTitle(QApplication::translate("ConfigSelect", "Config Select", nullptr));
        browseBtn->setText(QApplication::translate("ConfigSelect", "Browse", nullptr));
        openBtn->setText(QApplication::translate("ConfigSelect", "Open", nullptr));
        newBtn->setText(QApplication::translate("ConfigSelect", "New", nullptr));
        cancelBtn->setText(QApplication::translate("ConfigSelect", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigSelect: public Ui_ConfigSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGSELECT_H
