#ifndef CARREMOVEDEVENT_H
#define CARREMOVEDEVENT_H

#include "ievent.h"


class TrafficObjectRemovedEvent : public IEvent
{
public:
    TrafficObjectRemovedEvent(Position coordinates);
    std::string getName();
    Position getCoordinates();

private:
    Position coordinates_;
};

#endif // CARREMOVEDEVENT_H
