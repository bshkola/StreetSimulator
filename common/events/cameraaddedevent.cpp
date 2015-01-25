#include "../../common/events/cameraaddedevent.h"

CameraAddedEvent::CameraAddedEvent(int id, Coordinates coordinates) : IEvent(), id_(id) {
    coordinates_ = coordinates;
}

std::string CameraAddedEvent::getName() {
    return "CameraAdded";
}

int CameraAddedEvent::getId() {
    return id_;
}

Coordinates CameraAddedEvent::getCoordinates() {
    return coordinates_;
}
