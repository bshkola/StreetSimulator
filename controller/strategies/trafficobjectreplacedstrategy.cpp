#include "../../controller/strategies/trafficobjectreplacedstrategy.h"
#include "../../common/events/trafficobjectreplacedevent.h"

TrafficObjectReplacedStrategy::TrafficObjectReplacedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

TrafficObjectReplacedStrategy::~TrafficObjectReplacedStrategy() {
}

void TrafficObjectReplacedStrategy::perform(std::shared_ptr<IEvent> event) {
    TrafficObjectReplacedEvent* trafficObjectReplacedEvent = static_cast<TrafficObjectReplacedEvent*>(event.get());
    model_->replaceTrafficObject(trafficObjectReplacedEvent->getId(), trafficObjectReplacedEvent->getNewCoordinates());
}
