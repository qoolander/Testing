//
// Created by Sam on 10/01/2020.
//

#ifndef TESTING_MEMORYDISPLAY_H
#define TESTING_MEMORYDISPLAY_H

#include <QTableWidget>

class MemoryDisplay : public QTableWidget {
    Q_OBJECT
public:
    MemoryDisplay(QWidget *parent = nullptr);
protected:
    QSize sizeHint() const override
    {
        return QSize(parentWidget()->width()*0.1, parentWidget()->height());
    };

};


#endif //TESTING_MEMORYDISPLAY_H
