#include "../../common/events/trafficobjectaddedevent.h"

TrafficObjectAddedEvent::TrafficObjectAddedEvent(int id, Position coordinates, ObjectType objectType)
    : id_(id), coordinates_(coordinates), objectType_(objectType) {
}

std::string TrafficObjectAddedEvent::getName() {
    return "TrafficObjectAdded";
}

int TrafficObjectAddedEvent::getId() {
    return id_;
}

Position TrafficObjectAddedEvent::getCoordinates() {
    return coordinates_;
}

ObjectType TrafficObjectAddedEvent::getObjectType() {
    return objectType_;
}
