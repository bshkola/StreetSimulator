#include "../../controller/strategies/streetfieldremovedstrategy.h"

StreetFieldRemovedStrategy::StreetFieldRemovedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

StreetFieldRemovedStrategy::~StreetFieldRemovedStrategy() {
}

void StreetFieldRemovedStrategy::perform(std::shared_ptr<IEvent> event) {
    std::cout << "StreetFieldRemovedStrategy" << std::endl;
}
