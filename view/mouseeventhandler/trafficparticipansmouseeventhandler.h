#ifndef TRAFFICPARTICIPANSMOUSEEVENTHANDLER_H
#define TRAFFICPARTICIPANSMOUSEEVENTHANDLER_H

#include "mouseeventhandler.h"

class TrafficParticipansMouseEventHandler : public MouseEventHandler
{
public:
    TrafficParticipansMouseEventHandler();

    void handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);

private:
    static int indexCounter;
};

#endif // TRAFFICPARTICIPANSMOUSEEVENTHANDLER_H
