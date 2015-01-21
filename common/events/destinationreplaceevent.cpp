#include "../../common/events/destinationreplaceevent.h"

DestinationReplaceEvent::DestinationReplaceEvent(Coordinates oldCoordinates, Coordinates newCoordinates,
                                                 Coordinates trafficObjectCoordinates) : IEvent() {
    oldCoordinates_ = oldCoordinates;
    newCoordinates_ = newCoordinates;
    trafficObjectCoordinates_ = trafficObjectCoordinates;
}

std::string DestinationReplaceEvent::getName() {
    return "DestinationReplaced";
}

Coordinates DestinationReplaceEvent::getOldCoordinates() {
    return oldCoordinates_;
}

Coordinates DestinationReplaceEvent::getNewCoordinates() {
    return newCoordinates_;
}

Coordinates DestinationReplaceEvent::getTrafficObjectCoordinates() {
    return trafficObjectCoordinates_;
}
