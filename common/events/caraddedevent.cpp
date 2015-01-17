#include "../../common/events/caraddedevent.h"

CarAddedEvent::CarAddedEvent(Position coordinates)
    : coordinates_(coordinates)
{
}

std::string CarAddedEvent::getName()
{
    return "CarAdded";
}

Position CarAddedEvent::getCoordinates()
{
    return coordinates_;
}
