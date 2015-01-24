#ifndef DESTINATIONREPLACEEVENT_H
#define DESTINATIONREPLACEEVENT_H

#include "ievent.h"

class DestinationReplaceEvent : public IEvent
{
public:
    DestinationReplaceEvent(int trafficObjectId_, Coordinates newCoordinates);
    std::string getName();
    int getTrafficObjectId();
    Coordinates getNewCoordinates();


private:
    const int trafficObjectId_;
    Coordinates newCoordinates_;
};

#endif // DESTINATIONREPLACEEVENT_H
