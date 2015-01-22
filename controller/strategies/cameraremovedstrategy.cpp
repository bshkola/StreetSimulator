#include "../../controller/strategies/cameraremovedstrategy.h"
#include "../../common/events/cameraremovedevent.h"

CameraRemovedStrategy::CameraRemovedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

CameraRemovedStrategy::~CameraRemovedStrategy() {
}

void CameraRemovedStrategy::perform(std::shared_ptr<IEvent> event) {
    CameraRemovedEvent* cameraRemovedEvent = static_cast<CameraRemovedEvent*>(event.get());
    model_->removeCamera(cameraRemovedEvent->getCoordinates());
}
