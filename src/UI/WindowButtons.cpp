#include "WindowButtons.h"
#include <QHBoxLayout>
#include <QPushButton>

WindowButtons::WindowButtons(QWidget *parent)
	: QWidget(parent)
{
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	setStyleSheet("background-color : #271f1f");
	setMaximumWidth(height()*3);

	QPushButton *buttonClose = new QPushButton(this);
    QPushButton *buttonMax = new QPushButton(this);
    QPushButton *buttonMin = new QPushButton(this);
	
    buttonClose->setText("x");
	buttonClose->setStyleSheet("background-color : #271f1f; color : white;");
	buttonClose->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	buttonClose->setMaximumWidth(buttonClose->height());

    buttonMax->setText("@");
	buttonMax->setStyleSheet("background-color : #271f1f; color : white;");
	buttonMax->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	buttonMax->setMaximumWidth(buttonMax->height());

    buttonMin->setText("-");
	buttonMin->setStyleSheet("background-color : #271f1f; color : white;");
	buttonMin->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	buttonMin->setMaximumWidth(buttonMin->height());
 
    QObject::connect(buttonClose, SIGNAL(clicked()),this, SLOT(clickedSlot()));
    QObject::connect(buttonMax, SIGNAL(clicked()),this, SLOT(clickedSlot()));
    QObject::connect(buttonMin, SIGNAL(clicked()),this, SLOT(clickedSlot()));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(buttonMin);    
    layout->addWidget(buttonMax);
    layout->addWidget(buttonClose);

    layout->setMargin(0);
    layout->setSpacing(0);

    setLayout(layout);
}

void WindowButtons::clickedSlot(){
	if(((QPushButton*)sender())->text()=="x"){
		emit closeButtonClick();
	}else{
		if(((QPushButton*)sender())->text()=="@"){
			emit maximizeButtonClick();
		}else{
			emit minimizeButtonClick();
		}
	}
}