#ifndef MOUSEEVENTHANDLER_H
#define MOUSEEVENTHANDLER_H

#include "../boardscene.h"
#include <QGraphicsSceneMouseEvent>

class BoardScene;
class IMovableItem;

class MouseEventHandler
{
public:
    MouseEventHandler();

    virtual void handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) = 0;
    virtual void handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) = 0;
    virtual void handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) = 0;

};

#endif // MOUSEEVENTHANDLER_H
