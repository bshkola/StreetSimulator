//Author: Bogdan Shkola
//Event got when trafficobject is replaced
#ifndef CARREPLACEDEVENT_H
#define CARREPLACEDEVENT_H

#include "ievent.h"

class TrafficObjectReplacedEvent : public IEvent
{
public:
    TrafficObjectReplacedEvent(int id, Position newCoordinates);
    std::string getName();
    int getId();
    Position getNewCoordinates();

private:
    int id_;
    Position newCoordinates_;
};

#endif // CARREPLACEDEVENT_H
