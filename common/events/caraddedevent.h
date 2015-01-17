#ifndef CARADDEDEVENT_H
#define CARADDEDEVENT_H

#include "ievent.h"

class CarAddedEvent : public IEvent
{
public:
    CarAddedEvent(Position coordinates);
    std::string getName();
    Position getCoordinates();

private:
    Position coordinates_;
};

#endif // CARADDEDEVENT_H
