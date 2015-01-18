#include "../../common/events/camerareplacedevent.h"

CameraReplacedEvent::CameraReplacedEvent(Coordinates old_coordinates,
                                         Coordinates new_coordinates)
    : IEvent() {
    old_coordinates_ = old_coordinates;
    new_coordinates_ = new_coordinates;
}

std::string CameraReplacedEvent::getName() {
    return "CameraReplaced";
}

Coordinates CameraReplacedEvent::getOldCoordinates() {
    return old_coordinates_;
}

Coordinates CameraReplacedEvent::getNewCoordinates() {
    return new_coordinates_;
}
