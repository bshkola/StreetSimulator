#include "../../common/events/cameraaddedevent.h"

CameraAddedEvent::CameraAddedEvent(Coordinates coordinates)
    : IEvent() {
    coordinates_ = coordinates;
}

std::string CameraAddedEvent::getName() {
    return "CameraAdded";
}

Coordinates CameraAddedEvent::getCoordinates() {
    return coordinates_;
}
