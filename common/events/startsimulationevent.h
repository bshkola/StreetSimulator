//Author: Bogdan Shkola
//Event got when simulation is started
#ifndef STARTSIMULATIONEVENT_H
#define STARTSIMULATIONEVENT_H

#include "ievent.h"
#include "../../view/simulatorwindow.h"

class StartSimulationEvent : public IEvent
{
public:
    StartSimulationEvent(SimulatorWindow* simulatorWindow);
    std::string getName();
    SimulatorWindow* getSimulatorWindow();

private:
    SimulatorWindow* simulatorWindow_;
};

#endif // STARTSIMULATIONEVENT_H
