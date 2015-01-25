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
    virtual ~BoardScene();
    //Updates the resolution of the square board
    void updateBoardSize(int size);
    //Handle pressing the mouse in the scene
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    //Checks if the point is inside the graphics board (with menu items)
    bool isInsideBoard(const QPointF& pos);
    //Checks if the point is inside the graphics board scene
    bool isInsideScene(const QPointF& pos);

    //Gets discrete scene position representing the point
    QPointF getDiscretePosition(const QPointF& point);
    //Gets discrete coordinates of the cell in the point
    Position getDiscreteCoordinates(const QPointF& point);

    //Gets selected camera id (or -1 if no camera selected)
    int getActiveCameraId();

private:
    //Size of the board
    int boardSizeInPixels;
    //Size of the cell
    float shiftSize;
    //Size of the board in cells
    int boardSize;
    //Active item
    IMovableItem* activeMenuItem_;
    //last selected item
    IMovableItem* lastSelectedItem_;
};

#endif // BOARDSCENE_H
