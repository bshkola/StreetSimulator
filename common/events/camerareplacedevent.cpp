#include "../../common/events/camerareplacedevent.h"

CameraReplacedEvent::CameraReplacedEvent(int id, Coordinates new_coordinates) : IEvent(), id_(id), new_coordinates_(new_coordinates) {
}

std::string CameraReplacedEvent::getName() {
    return "CameraReplaced";
}

int CameraReplacedEvent::getId() {
    return id_;
}

Coordinates CameraReplacedEvent::getNewCoordinates() {
    return new_coordinates_;
}
