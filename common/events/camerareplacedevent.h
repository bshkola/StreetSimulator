#ifndef CAMERAREPLACEDEVENT_H
#define CAMERAREPLACEDEVENT_H

#include "ievent.h"

class CameraReplacedEvent : public IEvent
{
public:
    CameraReplacedEvent(int id, Coordinates new_coordinates);
    std::string getName();
    int getId();
    Coordinates getNewCoordinates();

private:
    const int id_;
    Coordinates new_coordinates_;
};

#endif // CAMERAREPLACEDEVENT_H
