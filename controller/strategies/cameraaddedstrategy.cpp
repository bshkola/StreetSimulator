#include "../../controller/strategies/cameraaddedstrategy.h"
#include "../../common/events/cameraaddedevent.h"

CameraAddedStrategy::CameraAddedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

CameraAddedStrategy::~CameraAddedStrategy() {
}

void CameraAddedStrategy::perform(std::shared_ptr<IEvent> event) {
    CameraAddedEvent* cameraAddedEvent = static_cast<CameraAddedEvent*>(event.get());
    model_->addCamera(cameraAddedEvent->getCoordinates());
}
