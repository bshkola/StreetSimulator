#include "../../common/events/carremovedevent.h"

CarRemovedEvent::CarRemovedEvent(Position coordinates)
    : coordinates_(coordinates)
{
}

std::string CarRemovedEvent::getName()
{
    return "CarRemoved";
}

Position CarRemovedEvent::getCoordinates()
{
    return coordinates_;
}
