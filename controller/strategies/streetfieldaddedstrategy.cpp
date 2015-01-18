#include "../../controller/strategies/streetfieldaddedstrategy.h"

StreetFieldAddedStrategy::StreetFieldAddedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void StreetFieldAddedStrategy::perform(IEvent* event)
{
    std::cout << "StreetFieldAddedStrategy" << std::endl;
}
