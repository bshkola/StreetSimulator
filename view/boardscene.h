//Author: Bogdan Shkola
//Representing graphics scene with a square street board.

#ifndef BOARDSCENE_H
#define BOARDSCENE_H

#include <QGraphicsScene>
#include "items/imovableitem.h"
#include "../common/types.h"

class IMovableItem;

class BoardScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit BoardScene();

    void updateBoardSize(int size); //updates the resolution of the square board
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    bool isInsideBoard(const QPointF& pos);
    bool isInsideScene(const QPointF& pos);

    QPointF getDiscretePosition(const QPointF& point);
    Position getDiscreteCoordinates(const QPointF& point);

protected:

signals:

public slots:

private:
    int boardSizeInPixels;
    float shiftSize;
    int boardSize;
    IMovableItem* activeMenuItem_;
    IMovableItem* lastSelectedItem_;


//        QPointF getPositionInsideBoard(const QPointF& screenPosition);

};

#endif // BOARDSCENE_H
