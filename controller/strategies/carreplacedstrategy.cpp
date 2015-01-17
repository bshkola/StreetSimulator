#include "../../controller/strategies/carreplacedstrategy.h"
#include "../../common/events/carreplacedevent.h"

CarReplacedStrategy::CarReplacedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void CarReplacedStrategy::perform(IEvent* event) {
    CarReplacedEvent* carReplacedEvent = static_cast<CarReplacedEvent*>(event);
    model_->replaceCar(carReplacedEvent->getOldCoordinates(), carReplacedEvent->getNewCoordinates());
    std::cout << "CarReplacedStrategy" << std::endl;
}
