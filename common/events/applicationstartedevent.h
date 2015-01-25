//Author: Bogdan Shkola
//Event got when application is started
#ifndef APPLICATIONSTARTEDEVENT_H
#define APPLICATIONSTARTEDEVENT_H

#include "ievent.h"

class ApplicationStartedEvent : public IEvent
{
public:
    ApplicationStartedEvent();

    std::string getName();
};

#endif // APPLICATIONSTARTEDEVENT_H
