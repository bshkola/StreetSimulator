#include "../../common/events/startsimulationevent.h"

StartSimulationEvent::StartSimulationEvent(SimulatorWindow* simulatorWindow) : IEvent(), simulatorWindow_(simulatorWindow) {
}

std::string StartSimulationEvent::getName() {
    return "StartSimulation";
}

SimulatorWindow* StartSimulationEvent::getSimulatorWindow() {
    return simulatorWindow_;
}
