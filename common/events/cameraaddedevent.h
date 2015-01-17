#ifndef CAMERAADDEDEVENT_H
#define CAMERAADDEDEVENT_H

#include "ievent.h"

class CameraAddedEvent : public IEvent
{
public:
    CameraAddedEvent(Coordinates coordinates);
    std::string getName();
    Coordinates getCoordinates();

private:
    Coordinates coordinates_;
};

#endif // CAMERAADDEDEVENT_H
