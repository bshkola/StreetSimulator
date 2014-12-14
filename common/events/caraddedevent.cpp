#include "caraddedevent.h"

CarAddedEvent::CarAddedEvent(Coordinates starting_coordinates, Coordinates destination_coordinates)
    : starting_coordinates_(starting_coordinates), destination_coordinates_(destination_coordinates)
{
}

std::string CarAddedEvent::getName()
{
    return "CarAdded";
}

Coordinates CarAddedEvent::getStartingCoordinates()
{
    return starting_coordinates_;
}

Coordinates CarAddedEvent::getDestinationCoordinates()
{
    return destination_coordinates_;
}
