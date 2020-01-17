#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QtDebug>
#include <QStatusBar> //TODO: Reconfigure my status bar to extend QStatusBar
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
    interpreter = new Interpreter();

	pressed = false;

	setWindowTitle(tr("Main Window by Sam"));
	//setWindowFlags( Qt::CustomizeWindowHint );
	resize(QDesktopWidget().availableGeometry(this).size() * 0.7);

	/*
	titleBar = new TitleBarWidget(this);
	titleBar->setMaximumHeight(height()*0.04);
	QObject::connect(titleBar, SIGNAL(signalMousePressed(int, int)), this, SLOT(titleMousePressed(int, int)));
	QObject::connect(titleBar, SIGNAL(signalMouseReleased()), this, SLOT(titleMouseReleased()));
	QObject::connect(titleBar->buttons, SIGNAL(closeButtonClick()), this, SLOT(closeButtonClick()));
	QObject::connect(titleBar->buttons, SIGNAL(maximizeButtonClick()), this, SLOT(maximizeButtonClick()));
    */ //Custom title bar

    configureMenuBar();

	mainPain = new QWidget();
	mainPain->setStyleSheet("background-color: #26596A;");

	QWidget *mainPainInner = new QWidget();
	mainPainInner->setStyleSheet("background-color: #372f2f; color: white;");

	QHBoxLayout *splitLayout = new QHBoxLayout;
    editor = new CodeEditor(this);
	editor->setMaximumWidth(width()*0.5);
	QWidget *displayPane = new QWidget();
	displayPane->setStyleSheet("background-color: #564949;");

    memDisplay = new MemoryDisplay(this);

	splitLayout->setMargin(0);
    splitLayout->addWidget(memDisplay);
	splitLayout->addWidget(editor);
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

	/*
    myStatusBar = new StatusBar(this);
	myStatusBar->setMaximumHeight(height() * 0.02);
	*/ //My Custom StatusBar --- possibly obsolete

	configureStatusBar();

	// Set layout
    QVBoxLayout *layout = new QVBoxLayout;
    //layout->addWidget(titleBar);
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
    switch(type){
    case QtInfoMsg:
		mainPain->setStyleSheet("background-color: #26596A;");
		statusBar()->setProperty("msgType", "info");
        statusBar()->showMessage(msg);
        break;
    case QtWarningMsg:
		mainPain->setStyleSheet("background-color: #AA5639;");
		qInfo()<< "msgType param is:" << statusBar()->property("msgType");
		statusBar()->showMessage("warning: " + msg);
		statusBar()->setProperty("msgType", "warning");
		break;
    default:
        mainPain->setStyleSheet("background-color: #26596A;");
        statusBar()->setProperty("msgType", "info");
        statusBar()->showMessage(msg);
    }
    statusBar()->repaint();
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

void MainWindow::configureMenuBar() {
    //menuBar()->setStyleSheet("background-color: #302020; color: white"); //TODO: Implement File stylesheet
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *newAct = new QAction( tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    //connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAct);

    QMenu *programMenu = menuBar()->addMenu(tr("Program"));
    QAction *runProgramAction = new QAction(tr("&run"), this);
    runProgramAction->setShortcut(Qt::Key_R);
    runProgramAction->setStatusTip(tr("Run current program"));
    connect(runProgramAction, &QAction::triggered, this, &MainWindow::runProgram);
    programMenu->addAction(runProgramAction);
}

void MainWindow::runProgram() {
    auto lines = editor->toPlainText().split("\n");
    bool *success = new bool;
    std::list<PART> data;
    data.push_front(0x01); //set instruction address to start of program;
    WORD current;
    int i = 1;
    try {
        for (auto item : lines) {
            if (item.length() != 8) {
                throw "unable to pass line " + QString::number(i, 16)  + ". Incorrect line length";
            }
            current = item.toUInt(success, 16);
            Q_ASSERT(success);
            data.push_back((short) ((current & 0xffff0000) >> (16)));
            data.push_back((short) (current & 0xffff));
            i += 2;
        }
    }catch (QString msg){
        qWarning()<<"Program failed to run: " << msg;
        return;
    }
    interpreter->initiateProgram(data);
}

void MainWindow::configureStatusBar() {
    statusBar()->setProperty("msgType", "info");
    statusBar()->showMessage(tr("Ready: "));
}
