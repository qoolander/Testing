#pragma once

#include <QWidget>


class WindowButtons : public QWidget{
	Q_OBJECT
public:
	WindowButtons(QWidget *parent = Q_NULLPTR);
signals:
	void closeButtonClick();
	void maximizeButtonClick();
	void minimizeButtonClick();
private slots:
	void clickedSlot();
};