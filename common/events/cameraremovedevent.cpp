#include "../../common/events/cameraremovedevent.h"

CameraRemovedEvent::CameraRemovedEvent(Coordinates coordinates) : IEvent() {
    coordinates_ = coordinates;
}

std::string CameraRemovedEvent::getName() {
    return "CameraRemoved";
}

Coordinates CameraRemovedEvent::getCoordinates() {
    return coordinates_;
}
