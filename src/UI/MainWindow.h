#pragma once
#include <QMainWindow>
#include "TitleBarWidget.h"
#include "StatusBar.h"
#include "CodeEditor.h"
#include "..\Interpreter\Interpreter.h"
#include "MemoryDisplay.h"

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
    void runProgram();
protected:
	TitleBarWidget* titleBar; 
	StatusBar* myStatusBar;
	QWidget *mainPain;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
	void configureMenuBar();
    void configureStatusBar();

	Interpreter *interpreter;
	CodeEditor *editor;
    MemoryDisplay *memDisplay;

	bool pressed;
    int offsetx;
    int offsety;
    bool max;

};

