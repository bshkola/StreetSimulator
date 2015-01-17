#ifndef CARADDEDEVENT_H
#define CARADDEDEVENT_H

#include "ievent.h"

class TrafficObjectAddedEvent : public IEvent
{
public:
    TrafficObjectAddedEvent(Position coordinates, ObjectType objectType);
    std::string getName();
    Position getCoordinates();
    ObjectType getObjectType();

private:
    Position coordinates_;
    ObjectType objectType_;
};

#endif // CARADDEDEVENT_H
