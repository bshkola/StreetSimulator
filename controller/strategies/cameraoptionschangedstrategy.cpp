//Author: Bogdan Shkola
//Implementation of CameraOptionsChangedStrategy class
#include "../../controller/strategies/cameraoptionschangedstrategy.h"
#include "../../common/events/cameraoptionschangedevent.h"

CameraOptionsChangedStrategy::CameraOptionsChangedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

CameraOptionsChangedStrategy::~CameraOptionsChangedStrategy() {
}

void CameraOptionsChangedStrategy::perform(std::shared_ptr<IEvent> event) {
    CameraOptionsChangedEvent* cameraOptionsChangedEvent = static_cast<CameraOptionsChangedEvent*>(event.get());
    model_->changeCameraOptions(cameraOptionsChangedEvent->getCameraId(), cameraOptionsChangedEvent->getCameraOptions());
}
