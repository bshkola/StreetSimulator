//Author: Bogdan Shkola
//Implementation of DestinationReplacedStrategy class
#include "../../controller/strategies/destinationreplacedstrategy.h"
#include "../../common/events/destinationreplaceevent.h"

DestinationReplacedStrategy::DestinationReplacedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

DestinationReplacedStrategy::~DestinationReplacedStrategy() {
}

void DestinationReplacedStrategy::perform(std::shared_ptr<IEvent> event) {
    DestinationReplaceEvent* destinationReplacedEvent = static_cast<DestinationReplaceEvent*>(event.get());
    model_->replaceDestination(destinationReplacedEvent->getTrafficObjectId(), destinationReplacedEvent->getNewCoordinates());
}
