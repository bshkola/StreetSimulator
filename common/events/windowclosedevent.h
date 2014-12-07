#ifndef WINDOWCLOSEDEVENT_H
#define WINDOWCLOSEDEVENT_H

#include "ievent.h"

class WindowClosedEvent : public IEvent
{
public:
    WindowClosedEvent();
    std::string getName();
};

#endif // WINDOWCLOSEDEVENT_H
