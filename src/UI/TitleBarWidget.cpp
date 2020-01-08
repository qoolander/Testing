#include "TitleBarWidget.h"

TitleBarWidget::TitleBarWidget(QWidget *parent)
	: QWidget(parent)
{	
	titleLabel = new QLabel(this);
	titleLabel->setText("Title");
	titleLabel->setContentsMargins(20, 0, 0, 0);
	QFont f( "Lato", 10);
	titleLabel->setFont(f);
	titleLabel->setStyleSheet("QLabel { background-color : #271f1f; color : white; }");
	titleLabel->setMinimumHeight(height());

	QWidget *panel = new QWidget(this);
    panel->setStyleSheet("background-color: #271f1f;");

    buttons = new WindowButtons(this);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(panel);
    layout->addWidget(titleLabel);
    layout->addWidget(buttons);

    layout->setSpacing(0);
	layout->setMargin(0);

	setLayout(layout);
}

void TitleBarWidget::mousePressEvent(QMouseEvent *event){
	emit signalMousePressed(event->globalX(),event->globalY());
}

void TitleBarWidget::mouseReleaseEvent(QMouseEvent *event){
	//mainWindow->titleMouseReleased();	
	emit signalMouseReleased();
}