#ifndef STARTSIMULATIONEVENT_H
#define STARTSIMULATIONEVENT_H

#include "ievent.h"

class StartSimulationEvent : public IEvent
{
public:
    StartSimulationEvent();
    std::string getName();
};

#endif // STARTSIMULATIONEVENT_H
