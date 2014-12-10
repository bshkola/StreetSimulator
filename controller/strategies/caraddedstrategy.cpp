#include "caraddedstrategy.h"

CarAddedStrategy::CarAddedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void CarAddedStrategy::perform(IEvent* event) {
    std::cout << "CarAddedStrategy" << std::endl;
}
