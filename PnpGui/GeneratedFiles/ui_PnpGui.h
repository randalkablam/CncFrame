/********************************************************************************
** Form generated from reading UI file 'PnpGui.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PNPGUI_H
#define UI_PNPGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PnpGuiClass
{
public:
    QAction *actionOpen_Config;
    QAction *actionNew_Config;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *motionTab;
    QGraphicsView *cameraScreen;
    QSlider *yAxisSlider;
    QSlider *xAxisSlider;
    QDoubleSpinBox *xAxisSpinBox;
    QDoubleSpinBox *yAxisSpinBox;
    QPushButton *homeBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *zAxisSpinBox;
    QPushButton *airOnBtn;
    QWidget *inventoryTab;
    QTableView *componentTableView;
    QWidget *schematicTab;
    QGraphicsView *graphicsView;
    QWidget *bitTab;
    QWidget *cmdTab;
    QTextBrowser *cmdBrowser;
    QLineEdit *cmdLine;
    QComboBox *cmdDest;
    QLabel *destLbl;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PnpGuiClass)
    {
        if (PnpGuiClass->objectName().isEmpty())
            PnpGuiClass->setObjectName(QStringLiteral("PnpGuiClass"));
        PnpGuiClass->resize(546, 325);
        actionOpen_Config = new QAction(PnpGuiClass);
        actionOpen_Config->setObjectName(QStringLiteral("actionOpen_Config"));
        actionNew_Config = new QAction(PnpGuiClass);
        actionNew_Config->setObjectName(QStringLiteral("actionNew_Config"));
        centralWidget = new QWidget(PnpGuiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 531, 281));
        motionTab = new QWidget();
        motionTab->setObjectName(QStringLiteral("motionTab"));
        cameraScreen = new QGraphicsView(motionTab);
        cameraScreen->setObjectName(QStringLiteral("cameraScreen"));
        cameraScreen->setGeometry(QRect(0, 0, 281, 201));
        yAxisSlider = new QSlider(motionTab);
        yAxisSlider->setObjectName(QStringLiteral("yAxisSlider"));
        yAxisSlider->setGeometry(QRect(280, 0, 16, 201));
        yAxisSlider->setOrientation(Qt::Vertical);
        xAxisSlider = new QSlider(motionTab);
        xAxisSlider->setObjectName(QStringLiteral("xAxisSlider"));
        xAxisSlider->setGeometry(QRect(0, 200, 281, 16));
        xAxisSlider->setOrientation(Qt::Horizontal);
        xAxisSpinBox = new QDoubleSpinBox(motionTab);
        xAxisSpinBox->setObjectName(QStringLiteral("xAxisSpinBox"));
        xAxisSpinBox->setGeometry(QRect(300, 30, 101, 26));
        xAxisSpinBox->setDecimals(4);
        yAxisSpinBox = new QDoubleSpinBox(motionTab);
        yAxisSpinBox->setObjectName(QStringLiteral("yAxisSpinBox"));
        yAxisSpinBox->setGeometry(QRect(300, 90, 101, 26));
        yAxisSpinBox->setDecimals(4);
        homeBtn = new QPushButton(motionTab);
        homeBtn->setObjectName(QStringLiteral("homeBtn"));
        homeBtn->setGeometry(QRect(300, 190, 89, 25));
        label = new QLabel(motionTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 10, 69, 17));
        label_2 = new QLabel(motionTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(300, 70, 69, 17));
        label_3 = new QLabel(motionTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 130, 69, 17));
        zAxisSpinBox = new QDoubleSpinBox(motionTab);
        zAxisSpinBox->setObjectName(QStringLiteral("zAxisSpinBox"));
        zAxisSpinBox->setGeometry(QRect(300, 150, 101, 26));
        zAxisSpinBox->setDecimals(4);
        airOnBtn = new QPushButton(motionTab);
        airOnBtn->setObjectName(QStringLiteral("airOnBtn"));
        airOnBtn->setGeometry(QRect(420, 30, 89, 25));
        airOnBtn->setCheckable(true);
        tabWidget->addTab(motionTab, QString());
        inventoryTab = new QWidget();
        inventoryTab->setObjectName(QStringLiteral("inventoryTab"));
        componentTableView = new QTableView(inventoryTab);
        componentTableView->setObjectName(QStringLiteral("componentTableView"));
        componentTableView->setGeometry(QRect(0, 0, 281, 221));
        tabWidget->addTab(inventoryTab, QString());
        schematicTab = new QWidget();
        schematicTab->setObjectName(QStringLiteral("schematicTab"));
        graphicsView = new QGraphicsView(schematicTab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 331, 221));
        tabWidget->addTab(schematicTab, QString());
        bitTab = new QWidget();
        bitTab->setObjectName(QStringLiteral("bitTab"));
        tabWidget->addTab(bitTab, QString());
        cmdTab = new QWidget();
        cmdTab->setObjectName(QStringLiteral("cmdTab"));
        cmdBrowser = new QTextBrowser(cmdTab);
        cmdBrowser->setObjectName(QStringLiteral("cmdBrowser"));
        cmdBrowser->setGeometry(QRect(0, 0, 521, 191));
        cmdLine = new QLineEdit(cmdTab);
        cmdLine->setObjectName(QStringLiteral("cmdLine"));
        cmdLine->setGeometry(QRect(0, 200, 521, 20));
        cmdDest = new QComboBox(cmdTab);
        cmdDest->setObjectName(QStringLiteral("cmdDest"));
        cmdDest->setGeometry(QRect(80, 220, 141, 22));
        destLbl = new QLabel(cmdTab);
        destLbl->setObjectName(QStringLiteral("destLbl"));
        destLbl->setGeometry(QRect(20, 220, 47, 13));
        tabWidget->addTab(cmdTab, QString());
        PnpGuiClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PnpGuiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 546, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        PnpGuiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PnpGuiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PnpGuiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PnpGuiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PnpGuiClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_Config);
        menuFile->addAction(actionNew_Config);

        retranslateUi(PnpGuiClass);
        QObject::connect(actionNew_Config, SIGNAL(triggered()), PnpGuiClass, SLOT(actionNewConfig()));
        QObject::connect(actionOpen_Config, SIGNAL(triggered()), PnpGuiClass, SLOT(actionOpenConfig()));
        QObject::connect(airOnBtn, SIGNAL(clicked()), PnpGuiClass, SLOT(actionAirOnClick()));
        QObject::connect(homeBtn, SIGNAL(clicked()), PnpGuiClass, SLOT(actionHomeClick()));
        QObject::connect(xAxisSlider, SIGNAL(sliderMoved(int)), PnpGuiClass, SLOT(actionXaxisMove()));
        QObject::connect(yAxisSlider, SIGNAL(sliderMoved(int)), PnpGuiClass, SLOT(actionYaxisMove()));
        QObject::connect(zAxisSpinBox, SIGNAL(valueChanged(double)), PnpGuiClass, SLOT(counterZAxis()));
        QObject::connect(yAxisSpinBox, SIGNAL(valueChanged(double)), PnpGuiClass, SLOT(counterYAxis()));
        QObject::connect(xAxisSpinBox, SIGNAL(valueChanged(double)), PnpGuiClass, SLOT(counterXAxis()));
        QObject::connect(cameraScreen, SIGNAL(rubberBandChanged(QRect,QPointF,QPointF)), PnpGuiClass, SLOT(dragView()));
        QObject::connect(cmdLine, SIGNAL(returnPressed()), PnpGuiClass, SLOT(cmdEntered()));
        QObject::connect(cmdDest, SIGNAL(currentTextChanged(QString)), PnpGuiClass, SLOT(cmdDestChanged()));

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(PnpGuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *PnpGuiClass)
    {
        PnpGuiClass->setWindowTitle(QApplication::translate("PnpGuiClass", "PnpGui", nullptr));
        actionOpen_Config->setText(QApplication::translate("PnpGuiClass", "Open Config", nullptr));
        actionNew_Config->setText(QApplication::translate("PnpGuiClass", "New Config", nullptr));
        homeBtn->setText(QApplication::translate("PnpGuiClass", "Home", nullptr));
        label->setText(QApplication::translate("PnpGuiClass", "X Axis", nullptr));
        label_2->setText(QApplication::translate("PnpGuiClass", "Y Axis", nullptr));
        label_3->setText(QApplication::translate("PnpGuiClass", "Z Axis", nullptr));
        airOnBtn->setText(QApplication::translate("PnpGuiClass", "Air On", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(motionTab), QApplication::translate("PnpGuiClass", "Motion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(inventoryTab), QApplication::translate("PnpGuiClass", "Inventory", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(schematicTab), QApplication::translate("PnpGuiClass", "Schematic", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(bitTab), QApplication::translate("PnpGuiClass", "BIT", nullptr));
        destLbl->setText(QApplication::translate("PnpGuiClass", "Dest Mgr", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(cmdTab), QApplication::translate("PnpGuiClass", "Prompt", nullptr));
        menuFile->setTitle(QApplication::translate("PnpGuiClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PnpGuiClass: public Ui_PnpGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PNPGUI_H
