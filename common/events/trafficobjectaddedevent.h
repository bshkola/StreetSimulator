#ifndef CARADDEDEVENT_H
#define CARADDEDEVENT_H

#include "ievent.h"

class TrafficObjectAddedEvent : public IEvent
{
public:
    TrafficObjectAddedEvent(int id, Position coordinates, ObjectType objectType);
    std::string getName();
    int getId();
    Position getCoordinates();
    ObjectType getObjectType();

private:
    int id_;
    Position coordinates_;
    ObjectType objectType_;
};

#endif // CARADDEDEVENT_H
