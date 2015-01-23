#include "../../controller/strategies/startsimulationstrategy.h"

StartSimulationStrategy::StartSimulationStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

StartSimulationStrategy::~StartSimulationStrategy() {
}

void StartSimulationStrategy::perform(std::shared_ptr<IEvent> event) {
    model_->startSimulation();
    view_->showSimulationWindow();
    view_->showSimulationBoard(model_->getBoard());
}
