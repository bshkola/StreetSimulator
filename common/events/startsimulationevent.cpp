#include "../../common/events/startsimulationevent.h"

StartSimulationEvent::StartSimulationEvent() : IEvent()
{
}

std::string StartSimulationEvent::getName() {
    return "StartSimulation";
}
