#pragma once
#include <QtDebug>
#include "UI/MainWindow.h"

class MessageHandler{
public:
    void handleMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static MessageHandler *getInstance();

    void setMainWindow(MainWindow *mainWindow);
private:
	MainWindow *mainWindow;
	MessageHandler();
	static MessageHandler *instance;
};