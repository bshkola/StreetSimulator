//Author: Bogdan Shkola
//Implementation of DestinationReplaceEvent class
#include "../../common/events/destinationreplaceevent.h"

DestinationReplaceEvent::DestinationReplaceEvent(int trafficObjectId, Coordinates newCoordinates)
    : IEvent(), trafficObjectId_(trafficObjectId), newCoordinates_(newCoordinates) {
}

std::string DestinationReplaceEvent::getName() {
    return "DestinationReplaced";
}

Coordinates DestinationReplaceEvent::getNewCoordinates() {
    return newCoordinates_;
}

int DestinationReplaceEvent::getTrafficObjectId() {
    return trafficObjectId_;
}
