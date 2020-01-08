#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QtDebug>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{

	pressed = false;

	setWindowTitle(tr("Main Window by Sam"));
	//setWindowFlags( Qt::CustomizeWindowHint );
	resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
	setStyleSheet("background-color: #372f2f;");

	titleBar = new TitleBarWidget(this);
	titleBar->setMaximumHeight(height()*0.04);
	QObject::connect(titleBar, SIGNAL(signalMousePressed(int, int)), this, SLOT(titleMousePressed(int, int)));
	QObject::connect(titleBar, SIGNAL(signalMouseReleased()), this, SLOT(titleMouseReleased()));
	QObject::connect(titleBar->buttons, SIGNAL(closeButtonClick()), this, SLOT(closeButtonClick()));
	QObject::connect(titleBar->buttons, SIGNAL(maximizeButtonClick()), this, SLOT(maximizeButtonClick()));

	mainPain = new QWidget();
	mainPain->setStyleSheet("background-color: #26596A;");

	QWidget *mainPainInner = new QWidget();
	mainPainInner->setStyleSheet("background-color: #372f2f; color: white;");

	QHBoxLayout *splitLayout = new QHBoxLayout;
	QTextEdit *textEditPane = new QTextEdit();
	textEditPane->setStyleSheet("background-color: #564949;");
	textEditPane->setMaximumWidth(width()*0.5);
	QWidget *displayPane = new QWidget();
	displayPane->setStyleSheet("background-color: #564949;");

	splitLayout->setMargin(0);
	splitLayout->addWidget(textEditPane);
	splitLayout->addWidget(displayPane);

	mainPainInner->setLayout(splitLayout);
	/*
			=======

		Split layout here

			=======
		 
	*/


	QVBoxLayout *innerLayout = new QVBoxLayout;
	innerLayout->addWidget(mainPainInner);
	innerLayout->setSpacing(0);
	innerLayout->setContentsMargins(1,0,1,1);
	mainPain->setLayout(innerLayout);

	statusBar = new StatusBar(this);
	statusBar->setMaximumHeight(height()*0.02);

	// Set layout
    QVBoxLayout *layout = new QVBoxLayout;
    //layout->addWidget(titleBar);
    layout->addWidget(mainPain);
    layout->addWidget(statusBar);

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
	qInfo() << "Moving!";
}
void MainWindow::titleMouseReleased(){
	pressed = false;

	qInfo() << "Not Moving!";
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
	if(pressed){
		move(event->globalX()-offsetx,event->globalY()-offsety);
	}	
}

void MainWindow::closeButtonClick(){
	close();
}



void MainWindow::message(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    statusBar->setStatus(type, msg);

    if(type==QtInfoMsg){
		mainPain->setStyleSheet("background-color: #26596A;");
    }else{
		mainPain->setStyleSheet("background-color: #AA5639;");
    }
}


void MainWindow::maximizeButtonClick()
{
	if(max){
    	showMaximized();
	}else{
		showNormal();
	}
	max=!max;
}
