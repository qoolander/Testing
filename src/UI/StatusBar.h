#pragma once

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class StatusBar : public QWidget{
	Q_OBJECT
public:
	StatusBar(QWidget *parent = Q_NULLPTR);
	void setStatus(QtMsgType type, QString msg);
private:
	QLabel *statusLabel;
};

