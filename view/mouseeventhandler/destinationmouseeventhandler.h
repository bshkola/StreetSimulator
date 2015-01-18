#ifndef DESTINATIONMOUSEEVENTHANDLER_H
#define DESTINATIONMOUSEEVENTHANDLER_H

#include "mouseeventhandler.h"

class DestinationMouseEventHandler : public MouseEventHandler
{
public:
    DestinationMouseEventHandler();

    void handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);

};

#endif // DESTINATIONMOUSEEVENTHANDLER_H
