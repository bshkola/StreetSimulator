#include "../../common/events/trafficobjectaddedevent.h"

TrafficObjectAddedEvent::TrafficObjectAddedEvent(Position coordinates, ObjectType objectType)
    : coordinates_(coordinates), objectType_(objectType) {
}

std::string TrafficObjectAddedEvent::getName() {
    return "TrafficObjectAdded";
}

Position TrafficObjectAddedEvent::getCoordinates() {
    return coordinates_;
}

ObjectType TrafficObjectAddedEvent::getObjectType() {
    return objectType_;
}
