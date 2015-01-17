#include "../../controller/strategies/trafficobjectremovedstrategy.h"
#include "../../common/events/trafficobjectremovedevent.h"

TrafficObjectRemovedStrategy::TrafficObjectRemovedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void TrafficObjectRemovedStrategy::perform(IEvent* event) {
    TrafficObjectRemovedEvent* carRemovedEvent = static_cast<TrafficObjectRemovedEvent*>(event);
    model_->removeTrafficObject(carRemovedEvent->getCoordinates());
    std::cout << "TrafficObjectRemovedStrategy" << std::endl;
}
