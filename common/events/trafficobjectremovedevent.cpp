#include "../../common/events/trafficobjectremovedevent.h"

TrafficObjectRemovedEvent::TrafficObjectRemovedEvent(Position coordinates)
    : coordinates_(coordinates)
{
}

std::string TrafficObjectRemovedEvent::getName()
{
    return "TrafficObjectRemoved";
}

Position TrafficObjectRemovedEvent::getCoordinates()
{
    return coordinates_;
}
