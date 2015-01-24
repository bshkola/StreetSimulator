#include "../../common/events/cameraremovedevent.h"

CameraRemovedEvent::CameraRemovedEvent(int id) : IEvent(), id_(id) {
}

std::string CameraRemovedEvent::getName() {
    return "CameraRemoved";
}

int CameraRemovedEvent::getId() {
    return id_;
}
