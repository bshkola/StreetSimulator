#include "streetfieldremovedstrategy.h"

StreetFieldRemovedStrategy::StreetFieldRemovedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}


void StreetFieldRemovedStrategy::perform(IEvent *event)
{
    std::cout << "StreetFieldRemovedStrategy" << std::endl;
}
