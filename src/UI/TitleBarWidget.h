#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QHBoxLayout>
#include "WindowButtons.h"

class TitleBarWidget : public QWidget{
	Q_OBJECT
public:
	TitleBarWidget(QWidget *parent = Q_NULLPTR);
	WindowButtons *buttons;
signals:
	void signalMousePressed(int x, int y);
	void signalMouseReleased();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
	QLabel *titleLabel;
};

