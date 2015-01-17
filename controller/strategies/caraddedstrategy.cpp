#include "../../controller/strategies/caraddedstrategy.h"
#include "../../common/events/caraddedevent.h"

CarAddedStrategy::CarAddedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void CarAddedStrategy::perform(IEvent* event) {
    CarAddedEvent* carAddedEvent = static_cast<CarAddedEvent*>(event);
    model_->addCar(carAddedEvent->getCoordinates());
    std::cout << "CarAddedStrategy" << std::endl;
}
