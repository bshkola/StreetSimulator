#ifndef CAMERAREMOVEDEVENT_H
#define CAMERAREMOVEDEVENT_H

#include "ievent.h"

class CameraRemovedEvent : public IEvent
{
public:
    CameraRemovedEvent(Coordinates coordinates);
    std::string getName();
    Coordinates getCoordinates();

private:
    Coordinates coordinates_;
};

#endif // CAMERAREMOVEDEVENT_H
