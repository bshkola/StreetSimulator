#include "../../common/events/carreplacedevent.h"

CarReplacedEvent::CarReplacedEvent(Position oldCoordinates, Position newCoordinates)
    : oldCoordinates_(oldCoordinates), newCoordinates_(newCoordinates)
{
}

std::string CarReplacedEvent::getName()
{
    return "CarReplaced";
}

Position CarReplacedEvent::getOldCoordinates()
{
    return oldCoordinates_;
}

Position CarReplacedEvent::getNewCoordinates()
{
    return newCoordinates_;
}
