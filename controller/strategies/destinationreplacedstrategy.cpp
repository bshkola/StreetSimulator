#include "../../controller/strategies/destinationreplacedstrategy.h"
#include "../../common/events/destinationreplaceevent.h"

DestinationReplacedStrategy::DestinationReplacedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void DestinationReplacedStrategy::perform(IEvent* event) {
    DestinationReplaceEvent* destinationReplacedEvent = static_cast<DestinationReplaceEvent*>(event);
    model_->replaceDestination(destinationReplacedEvent->getOldCoordinates(), destinationReplacedEvent->getNewCoordinates(), destinationReplacedEvent->getTrafficObjectCoordinates());
    std::cout << "CameraReplacedStrategy" << std::endl;
}
