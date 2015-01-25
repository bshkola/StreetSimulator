//Author: Bogdan Shkola
//Handler for mouse pressing events on the destination items
#ifndef DESTINATIONMOUSEEVENTHANDLER_H
#define DESTINATIONMOUSEEVENTHANDLER_H

#include "mouseeventhandler.h"

class DestinationMouseEventHandler : public MouseEventHandler
{
    DestinationMouseEventHandler();
public:
    //Handles mouse pressing on the items
    void handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);

    //Singleton
    static DestinationMouseEventHandler* getInstance() {
        static DestinationMouseEventHandler instance;
        return &instance;
    }
};

#endif // DESTINATIONMOUSEEVENTHANDLER_H
