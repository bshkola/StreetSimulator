#include "boardscene.h"
#include <iostream>

BoardScene::BoardScene() : QGraphicsScene()
{
    borderSize = 300;
}

void BoardScene::updateBoardSize(int size) {
    this->clear();

    QPen blackPen(Qt::black);
    QBrush noBrush(Qt::NoBrush);

    this->addRect(0, 0, borderSize, borderSize, blackPen, noBrush);
    float shiftSize = std::min(width(), height()) / size;
    for (int i = 1; i < size; ++i) {
        addLine(i * shiftSize, 0, i * shiftSize, borderSize);
        addLine(0, i * shiftSize, borderSize, i * shiftSize);
    }
}
