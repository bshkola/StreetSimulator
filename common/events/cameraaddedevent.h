//Author: Bogdan Shkola
//Event got when camera is added
#ifndef CAMERAADDEDEVENT_H
#define CAMERAADDEDEVENT_H

#include "ievent.h"

class CameraAddedEvent : public IEvent
{
public:
    CameraAddedEvent(int id, Coordinates coordinates);
    std::string getName();
    int getId();
    Coordinates getCoordinates();

private:
    const int id_;
    Coordinates coordinates_;
};

#endif // CAMERAADDEDEVENT_H
