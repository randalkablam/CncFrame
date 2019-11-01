#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PnpGui.h"

class HighLevelGui;

class PnpGui : public QMainWindow
{
	Q_OBJECT

public:
	PnpGui(HighLevelGui* hlg, QWidget *parent );

public slots:
	void actionOpenConfig(bool checked = false);
	void actionNewConfig(bool checked = false);
	void actionAirOnClick();
	void actionHomeClick();
	void actionXaxisMove(int32_t i);
	void actionYaxisMove(int32_t i);
	void counterZAxis(double d);
	void counterYAxis(double d);
	void counterXAxis(double d);
	void dragView(QRect rect, QPointF start, QPointF end);
	void cmdEntered(void);
	void cmdDestChanged(QString& str);
private:
	Ui::PnpGuiClass ui;

	HighLevelGui* m_highLevelGui;

};
