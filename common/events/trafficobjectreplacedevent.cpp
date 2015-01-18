#include "../../common/events/trafficobjectreplacedevent.h"

TrafficObjectReplacedEvent::TrafficObjectReplacedEvent(Position oldCoordinates, Position newCoordinates)
    : oldCoordinates_(oldCoordinates), newCoordinates_(newCoordinates)
{
}

std::string TrafficObjectReplacedEvent::getName()
{
    return "TrafficObjectReplaced";
}

Position TrafficObjectReplacedEvent::getOldCoordinates()
{
    return oldCoordinates_;
}

Position TrafficObjectReplacedEvent::getNewCoordinates()
{
    return newCoordinates_;
}
