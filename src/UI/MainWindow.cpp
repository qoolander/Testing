#include "MainWindow.h"
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	offsetx = 1; offsety = 1;

	setWindowTitle(tr("Main Window by Sam"));
	setWindowFlags(Qt::FramelessWindowHint);
	resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
	setStyleSheet("background-color: #372f2f;");

	titleBar = new TitleBarWidget(this);
	titleBar->setStyleSheet("background-color: #473f3f;");
	titleBar->setMaximumHeight(80);
	QObject::connect(titleBar, SIGNAL(signalMousePressed(int, int)), this, SLOT(titleMousePressed(int, int)));
	QObject::connect(titleBar, SIGNAL(signalMouseReleased()), this, SLOT(titleMouseReleased()));

	QWidget *mainPain = new QWidget();

	// Set layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titleBar);
    layout->addWidget(mainPain);

    layout->setSpacing(0);
	layout->setMargin(0);
   	
    // Set layout in QWidget
    QWidget *window = new QWidget();
    window->setLayout(layout);

    // Set QWidget as the central layout of the main window
    setCentralWidget(window);
}

void MainWindow::titleMousePressed(int px, int py){
	offsetx = px - pos().x();
	offsety = py - pos().y();
	pressed = true;
}
void MainWindow::titleMouseReleased(){
	pressed = false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
	if(pressed){
		move(event->globalX()-offsetx,event->globalY()-offsety);
	}	
}