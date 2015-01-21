#include "streetfieldaddedevent.h"

StreetFieldAddedEvent::StreetFieldAddedEvent(Coordinates coordinates) : coordinates_(coordinates) {
}

std::string StreetFieldAddedEvent::getName() {
    return "StreetFieldAdded";
}

Coordinates StreetFieldAddedEvent::getCoordinates() {
    return coordinates_;
}

