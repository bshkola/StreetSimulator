#include "streetfieldremovedevent.h"

StreetFieldRemovedEvent::StreetFieldRemovedEvent(Position coordinates) : coordinates_(coordinates) {
}

std::string StreetFieldRemovedEvent::getName() {
    return "StreetFieldRemoved";
}

Position StreetFieldRemovedEvent::getCoordinates() {
    return coordinates_;
}
