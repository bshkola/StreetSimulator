#ifndef CAMERAOPTIONSCHANGEDEVENT_H
#define CAMERAOPTIONSCHANGEDEVENT_H

#include "ievent.h"
#include "../cameraoptions.h"

class CameraOptionsChangedEvent : public IEvent
{
public:
    CameraOptionsChangedEvent(int cameraId, CameraOptions cameraOptions);
    std::string getName();
    int getCameraId();
    CameraOptions getCameraOptions();

private:
    int cameraId_;
    CameraOptions cameraOptions_;
};

#endif // CAMERAOPTIONSCHANGEDEVENT_H
