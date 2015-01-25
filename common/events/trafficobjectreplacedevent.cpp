//Author: Bogdan Shkola
//Implementation of TrafficObjectReplacedEvent class
#include "../../common/events/trafficobjectreplacedevent.h"

TrafficObjectReplacedEvent::TrafficObjectReplacedEvent(int id, Position newCoordinates)
    : id_(id), newCoordinates_(newCoordinates) {
}

std::string TrafficObjectReplacedEvent::getName() {
    return "TrafficObjectReplaced";
}

int TrafficObjectReplacedEvent::getId() {
    return id_;
}

Position TrafficObjectReplacedEvent::getNewCoordinates() {
    return newCoordinates_;
}
