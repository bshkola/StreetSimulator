#include "../../controller/strategies/destinationreplacedstrategy.h"
#include "../../common/events/destinationreplaceevent.h"

DestinationReplacedStrategy::DestinationReplacedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view)
{
}

DestinationReplacedStrategy::~DestinationReplacedStrategy() {
}

void DestinationReplacedStrategy::perform(IEvent* event) {
    DestinationReplaceEvent* destinationReplacedEvent = static_cast<DestinationReplaceEvent*>(event);
    model_->replaceDestination(destinationReplacedEvent->getOldCoordinates(), destinationReplacedEvent->getNewCoordinates(), destinationReplacedEvent->getTrafficObjectCoordinates());
    std::cout << "CameraReplacedStrategy" << std::endl;
}
