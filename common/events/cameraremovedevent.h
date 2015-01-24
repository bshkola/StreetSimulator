#ifndef CAMERAREMOVEDEVENT_H
#define CAMERAREMOVEDEVENT_H

#include "ievent.h"

class CameraRemovedEvent : public IEvent
{
public:
    CameraRemovedEvent(int id);
    std::string getName();
    int getId();

private:
    const int id_;
};

#endif // CAMERAREMOVEDEVENT_H
