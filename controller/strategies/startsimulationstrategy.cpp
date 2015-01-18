#include "../../controller/strategies/startsimulationstrategy.h"

StartSimulationStrategy::StartSimulationStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void StartSimulationStrategy::perform(IEvent* event)
{
    model_->startSimulation();
    std::cout << "StartSimulationStrategy" << std::endl;
}
