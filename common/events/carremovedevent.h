#ifndef CARREMOVEDEVENT_H
#define CARREMOVEDEVENT_H

#include "ievent.h"


class CarRemovedEvent : public IEvent
{
public:
    CarRemovedEvent(Position coordinates);
    std::string getName();
    Position getCoordinates();

private:
    Position coordinates_;
};

#endif // CARREMOVEDEVENT_H
