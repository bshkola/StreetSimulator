#include "../../controller/strategies/startsimulationstrategy.h"
#include "../../common/events/startsimulationevent.h"

StartSimulationStrategy::StartSimulationStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

StartSimulationStrategy::~StartSimulationStrategy() {
}

void StartSimulationStrategy::perform(std::shared_ptr<IEvent> event) {
    StartSimulationEvent* startSimulationEvent = static_cast<StartSimulationEvent*>(event.get());

    model_->startSimulation(startSimulationEvent->getSimulatorWindow());
}
