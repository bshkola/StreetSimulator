//Author: Bogdan Shkola
//Implementation of StreetFieldAddedEvent class
#include "streetfieldaddedevent.h"

StreetFieldAddedEvent::StreetFieldAddedEvent(Position coordinates) : coordinates_(coordinates) {
}

std::string StreetFieldAddedEvent::getName() {
    return "StreetFieldAdded";
}

Position StreetFieldAddedEvent::getCoordinates() {
    return coordinates_;
}

