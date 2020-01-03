#include "TitleBarWidget.h"

TitleBarWidget::TitleBarWidget(QWidget *parent)
	: QWidget(parent)
{
}

void TitleBarWidget::mousePressEvent(QMouseEvent *event){
	emit signalMousePressed(event->globalX(),event->globalY());
}

void TitleBarWidget::mouseReleaseEvent(QMouseEvent *event){
	//mainWindow->titleMouseReleased();	
	emit signalMouseReleased();
}