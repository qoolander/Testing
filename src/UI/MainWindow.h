#pragma once
#include <QMainWindow>
#include "TitleBarWidget.h"
#include "StatusBar.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	void message(QtMsgType type, const QMessageLogContext &context, const QString &msg);
protected slots:	
    void titleMousePressed(int px, int py);
    void titleMouseReleased();
    void closeButtonClick();
    void maximizeButtonClick();
protected:
	TitleBarWidget* titleBar; 
	StatusBar* statusBar;
	QWidget *mainPain;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
	bool pressed;
    int offsetx;
    int offsety;
    bool max;
};

