#include "../../controller/strategies/startsimulationstrategy.h"

StartSimulationStrategy::StartSimulationStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view)
{
}

StartSimulationStrategy::~StartSimulationStrategy() {
}

void StartSimulationStrategy::perform(IEvent* event)
{
    model_->startSimulation();
    std::cout << "StartSimulationStrategy" << std::endl;
}
