//
// Created by Sam on 10/01/2020.
//

#include "MemoryDisplay.h"


MemoryDisplay::MemoryDisplay(QWidget *parent) : QTableWidget(parent){
    setFrameStyle(QFrame::NoFrame);

    setRowCount(5);
    setColumnCount(2);
}

