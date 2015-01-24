#include "../../controller/strategies/camerareplacedstrategy.h"
#include "../../common/events/camerareplacedevent.h"

CameraReplacedStrategy::CameraReplacedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

CameraReplacedStrategy::~CameraReplacedStrategy() {
}

void CameraReplacedStrategy::perform(std::shared_ptr<IEvent> event) {
    CameraReplacedEvent* cameraReplacedEvent = static_cast<CameraReplacedEvent*>(event.get());
    model_->replaceCamera(cameraReplacedEvent->getId(), cameraReplacedEvent->getNewCoordinates());
    view_->setCameraOptions(model_->getCameraOptions(cameraReplacedEvent->getId()));
}
