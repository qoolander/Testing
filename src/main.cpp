#include <iostream>
#include <QtDebug>
#include "Factorial.h"
#include <QtWidgets/QApplication>
#include "UI/MainWindow.h"
#include "MessageHandler.h"

void _handleMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg){
		MessageHandler::getInstance()->handleMessage(type, context, msg);
}


//Initialize pointer to zero so that it can be initialized in first call to getInstance
MessageHandler *MessageHandler::instance = 0;

int main(int argc, char *argv[]) {
	std::cout << "Hello CMake!\n" << "The factorial of 5 is ";
	std::cout << Factorial(5) << "\n";

	QApplication a(argc, argv);
    
	MainWindow w;
	
	MessageHandler *mh = mh->getInstance();
	mh->setMainWindow(&w);


	qInstallMessageHandler(_handleMessage);
	w.show();
	return a.exec();
}