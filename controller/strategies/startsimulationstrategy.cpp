//Author: Bogdan Shkola
//Implementation of StartSimulationStrategy class
#include "../../controller/strategies/startsimulationstrategy.h"
#include "../../common/events/startsimulationevent.h"
#include "../../common/exceptions/notwaybetweensourceanddestinationtargetpointexceptions.h"

StartSimulationStrategy::StartSimulationStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

StartSimulationStrategy::~StartSimulationStrategy() {
}

void StartSimulationStrategy::perform(std::shared_ptr<IEvent> event) {
    StartSimulationEvent* startSimulationEvent = static_cast<StartSimulationEvent*>(event.get());

    try {
        model_->startSimulation(startSimulationEvent->getSimulatorWindow());
    } catch(NotWayBetweenSourceAndDestinationTargetPointExceptions ex) {
        view_->showMessageSignal(ex.message());
        std::cout << "Done" ;
    }
}
