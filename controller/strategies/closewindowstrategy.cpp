//Author: Bogdan Shkola
//Implementation of CloseWindowStrategy class
#include "../../controller/strategies/closewindowstrategy.h"

CloseWindowStrategy::CloseWindowStrategy(IController& controller) : controller_(&controller) {
}

CloseWindowStrategy::~CloseWindowStrategy() {
}

void CloseWindowStrategy::perform(std::shared_ptr<IEvent> event) {
    controller_->finish();
}
