#include "../../controller/strategies/carremovedstrategy.h"
#include "../../common/events/carremovedevent.h"

CarRemovedStrategy::CarRemovedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void CarRemovedStrategy::perform(IEvent* event) {
    CarRemovedEvent* carRemovedEvent = static_cast<CarRemovedEvent*>(event);
    model_->removeCar(carRemovedEvent->getCoordinates());
    std::cout << "CarRemovedStrategy" << std::endl;
}
