#pragma once
#include <QMainWindow>
#include "TitleBarWidget.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = Q_NULLPTR);
protected slots:	
    void titleMousePressed(int px, int py);
    void titleMouseReleased();
protected:
	TitleBarWidget* titleBar; 
    void mouseMoveEvent(QMouseEvent *event) override;
private:
	bool pressed;
    int offsetx;
    int offsety;
};
