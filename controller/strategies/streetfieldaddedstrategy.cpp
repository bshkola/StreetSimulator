#include "../../controller/strategies/streetfieldaddedstrategy.h"

StreetFieldAddedStrategy::StreetFieldAddedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view)
{
}

StreetFieldAddedStrategy::~StreetFieldAddedStrategy() {
}

void StreetFieldAddedStrategy::perform(IEvent* event)
{
    std::cout << "StreetFieldAddedStrategy" << std::endl;
}
