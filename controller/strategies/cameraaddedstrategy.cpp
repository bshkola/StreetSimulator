#include "../../controller/strategies/cameraaddedstrategy.h"
#include "../../common/events/cameraaddedevent.h"

CameraAddedStrategy::CameraAddedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void CameraAddedStrategy::perform(IEvent* event) {
    CameraAddedEvent* cameraAddedEvent = static_cast<CameraAddedEvent*>(event);
    model_->addCamera(cameraAddedEvent->getCoordinates());
    std::cout << "CameraAddedStrategy" << std::endl;
}
