#pragma once
#include <QWidget>
#include <QMouseEvent>

class TitleBarWidget : public QWidget{
	Q_OBJECT
public:
	TitleBarWidget(QWidget *parent = Q_NULLPTR);
signals:
	void signalMousePressed(int x, int y);
	void signalMouseReleased();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public:
	
};

