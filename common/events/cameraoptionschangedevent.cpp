//Author: Bogdan Shkola
//Implementation of CameraOptionsChangedEvent class
#include "../../common/events/cameraoptionschangedevent.h"

CameraOptionsChangedEvent::CameraOptionsChangedEvent(int cameraId, CameraOptions cameraOptions)
    : cameraId_(cameraId), cameraOptions_(cameraOptions) {
}

std::string CameraOptionsChangedEvent::getName() {
    return "CameraOptionsChanged";
}

int CameraOptionsChangedEvent::getCameraId() {
    return cameraId_;
}

CameraOptions CameraOptionsChangedEvent::getCameraOptions() {
    return cameraOptions_;
}
