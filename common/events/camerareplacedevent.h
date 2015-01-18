#ifndef CAMERAREPLACEDEVENT_H
#define CAMERAREPLACEDEVENT_H

#include "ievent.h"

class CameraReplacedEvent : public IEvent
{
public:
    CameraReplacedEvent(Coordinates old_coordinates, Coordinates new_coordinates);
    std::string getName();
    Coordinates getOldCoordinates();
    Coordinates getNewCoordinates();

private:
    Coordinates old_coordinates_;
    Coordinates new_coordinates_;
};

#endif // CAMERAREPLACEDEVENT_H
