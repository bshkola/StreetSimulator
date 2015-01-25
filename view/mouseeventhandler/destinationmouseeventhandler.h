#ifndef DESTINATIONMOUSEEVENTHANDLER_H
#define DESTINATIONMOUSEEVENTHANDLER_H

#include "mouseeventhandler.h"

class DestinationMouseEventHandler : public MouseEventHandler
{
    DestinationMouseEventHandler();
public:

    void handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);

    static DestinationMouseEventHandler* getInstance() {
        static DestinationMouseEventHandler instance;
        return &instance;
    }
};

#endif // DESTINATIONMOUSEEVENTHANDLER_H
