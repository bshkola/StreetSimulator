#include "../../controller/strategies/camerareplacedstrategy.h"
#include "../../common/events/camerareplacedevent.h"

CameraReplacedStrategy::CameraReplacedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void CameraReplacedStrategy::perform(IEvent* event) {
    CameraReplacedEvent* cameraAddedEvent = static_cast<CameraReplacedEvent*>(event);
    model_->replaceCamera(cameraAddedEvent->getOldCoordinates(), cameraAddedEvent->getNewCoordinates());
    std::cout << "CameraReplacedStrategy" << std::endl;
}
