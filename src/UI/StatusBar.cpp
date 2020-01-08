#include "StatusBar.h"
#include <QHBoxLayout>
#include <QtDebug>

StatusBar::StatusBar(QWidget *parent)
	: QWidget(parent)
{
	setStyleSheet("background-color: #26596A;");

	statusLabel = new QLabel();
	statusLabel->setText("Ready:");
	QFont f( "Lato", 8);
	statusLabel->setFont(f);
	statusLabel->setStyleSheet("color: white; ");
	statusLabel->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
	statusLabel->setIndent(6);

	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(statusLabel);

	layout->setMargin(0);
	layout->setSpacing(0);

	setLayout(layout);

}


void StatusBar::setStatus(QtMsgType type, QString msg)
{
	if(!QtDebugMsg){
    	if(type == QtInfoMsg){
    		setStyleSheet("background-color: #26596A;");
    		statusLabel->setText(QString("Info: %1").arg(msg));
    		statusLabel->adjustSize();
    	}else{
			setStyleSheet("background-color: #AA5639;");

    		statusLabel->setText(QString("Warning: %1").arg(msg));
    	}
	}
}
