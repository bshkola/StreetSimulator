//Author: Bogdan Shkola
//Handler for mouse pressing events on the traffic items
#ifndef TRAFFICPARTICIPANSMOUSEEVENTHANDLER_H
#define TRAFFICPARTICIPANSMOUSEEVENTHANDLER_H

#include "mouseeventhandler.h"

class TrafficParticipansMouseEventHandler : public MouseEventHandler
{
    TrafficParticipansMouseEventHandler();
public:
    //Handles mouse pressing on the items
    void handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);

    //Singleton
    static TrafficParticipansMouseEventHandler* getInstance() {
        static TrafficParticipansMouseEventHandler instance;
        return &instance;
    }

private:
    //Counter of the index for traffic items
    static int indexCounter_;
};

#endif // TRAFFICPARTICIPANSMOUSEEVENTHANDLER_H
