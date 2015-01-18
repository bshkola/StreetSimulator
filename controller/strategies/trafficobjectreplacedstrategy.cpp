#include "../../controller/strategies/trafficobjectreplacedstrategy.h"
#include "../../common/events/trafficobjectreplacedevent.h"

TrafficObjectReplacedStrategy::TrafficObjectReplacedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void TrafficObjectReplacedStrategy::perform(IEvent* event) {
    TrafficObjectReplacedEvent* trafficObjectReplacedEvent = static_cast<TrafficObjectReplacedEvent*>(event);
    model_->replaceTrafficObject(trafficObjectReplacedEvent->getOldCoordinates(), trafficObjectReplacedEvent->getNewCoordinates());
    std::cout << "TrafficObjectReplacedStrategy" << std::endl;
}
