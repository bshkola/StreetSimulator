//Author: Bogdan Shkola
//Implementation of TrafficObjectRemovedEvent class
#include "../../common/events/trafficobjectremovedevent.h"

TrafficObjectRemovedEvent::TrafficObjectRemovedEvent(int id)
    : id_(id) {
}

std::string TrafficObjectRemovedEvent::getName() {
    return "TrafficObjectRemoved";
}

int TrafficObjectRemovedEvent::getId() {
    return id_;
}

