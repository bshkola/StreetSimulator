#ifndef DESTINATIONREPLACEEVENT_H
#define DESTINATIONREPLACEEVENT_H

#include "ievent.h"

class DestinationReplaceEvent : public IEvent
{
public:
    DestinationReplaceEvent(Coordinates oldCoordinates, Coordinates newCoordinates, Coordinates trafficObjectCoordinates);
    std::string getName();
    Coordinates getOldCoordinates();
    Coordinates getNewCoordinates();
    Coordinates getTrafficObjectCoordinates();

private:
    Coordinates oldCoordinates_;
    Coordinates newCoordinates_;
    Coordinates trafficObjectCoordinates_;
};

#endif // DESTINATIONREPLACEEVENT_H
