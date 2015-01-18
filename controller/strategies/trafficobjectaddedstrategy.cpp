#include "../../controller/strategies/trafficobjectaddedstrategy.h"
#include "../../common/events/trafficobjectaddedevent.h"

TrafficObjectAddedStrategy::TrafficObjectAddedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void TrafficObjectAddedStrategy::perform(IEvent* event) {
    TrafficObjectAddedEvent* carAddedEvent = static_cast<TrafficObjectAddedEvent*>(event);
    model_->addTrafficObject(carAddedEvent->getCoordinates(), carAddedEvent->getObjectType());
    std::cout << "TrafficObjectAddedStrategy" << std::endl;
}
