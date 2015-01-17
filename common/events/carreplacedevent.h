#ifndef CARREPLACEDEVENT_H
#define CARREPLACEDEVENT_H

#include "ievent.h"

class CarReplacedEvent : public IEvent
{
public:
    CarReplacedEvent(Position oldCoordinates, Position newCoordinates);
    std::string getName();
    Position getOldCoordinates();
    Position getNewCoordinates();

private:
    Position oldCoordinates_;
    Position newCoordinates_;
};

#endif // CARREPLACEDEVENT_H
