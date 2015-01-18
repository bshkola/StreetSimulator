#include "../../controller/strategies/camerareplacedstrategy.h"
#include "../../common/events/camerareplacedevent.h"

CameraReplacedStrategy::CameraReplacedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view)
{
}

CameraReplacedStrategy::~CameraReplacedStrategy() {
}

void CameraReplacedStrategy::perform(IEvent* event) {
    CameraReplacedEvent* cameraReplacedEvent = static_cast<CameraReplacedEvent*>(event);
    model_->replaceCamera(cameraReplacedEvent->getOldCoordinates(), cameraReplacedEvent->getNewCoordinates());
    std::cout << "CameraReplacedStrategy" << std::endl;
}
