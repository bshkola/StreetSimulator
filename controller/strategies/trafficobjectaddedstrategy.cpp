#include "../../controller/strategies/trafficobjectaddedstrategy.h"
#include "../../common/events/trafficobjectaddedevent.h"

TrafficObjectAddedStrategy::TrafficObjectAddedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

TrafficObjectAddedStrategy::~TrafficObjectAddedStrategy() {
}

void TrafficObjectAddedStrategy::perform(std::shared_ptr<IEvent> event) {
    TrafficObjectAddedEvent* carAddedEvent = static_cast<TrafficObjectAddedEvent*>(event.get());
    model_->addTrafficObject(carAddedEvent->getCoordinates(), carAddedEvent->getObjectType());
}
