//Author: Bogdan Shkola
//Representing graphics scene with a square street board.

#ifndef BOARDSCENE_H
#define BOARDSCENE_H

#include <QGraphicsScene>
#include "imovableitem.h"

namespace Ui {
    class BoardScene : public QGraphicsScene
    {
        Q_OBJECT
    public:
        explicit BoardScene();

        void updateBoardSize(int size); //updates the resolution of the square board
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    protected:

    signals:

    public slots:

    private:
        int boardSizeInPixels;
        float shiftSize;
        int boardSize;
        IMovableItem* movingItem_;

        bool isInsideBoard(const QPointF& pos);
        bool isInsideScene(const QPointF& pos);
//        QPointF getPositionInsideBoard(const QPointF& screenPosition);

    };
}
#endif // BOARDSCENE_H
