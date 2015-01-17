#ifndef CARADDEDEVENT_H
#define CARADDEDEVENT_H

#include "ievent.h"
#include "../../common/types.h"

class CarAddedEvent : public IEvent
{
public:
    CarAddedEvent(Coordinates starting_coordinates, Coordinates destination_coordinates);
    std::string getName();
    Coordinates getStartingCoordinates();
    Coordinates getDestinationCoordinates();

private:
    Coordinates starting_coordinates_;
    Coordinates destination_coordinates_;
};

#endif // CARADDEDEVENT_H
