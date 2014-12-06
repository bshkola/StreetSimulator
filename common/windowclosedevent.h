#ifndef WINDOWCLOSEDEVENT_H
#define WINDOWCLOSEDEVENT_H

#include "event.h"

class WindowClosedEvent : public Event
{
public:
    WindowClosedEvent();
    std::string getName();
};

#endif // WINDOWCLOSEDEVENT_H
