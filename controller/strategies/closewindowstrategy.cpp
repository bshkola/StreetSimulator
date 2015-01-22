#include "../../controller/strategies/closewindowstrategy.h"

CloseWindowStrategy::CloseWindowStrategy(IController& controller) : controller_(&controller) {
}

CloseWindowStrategy::~CloseWindowStrategy() {
    std::cout << "~CloseWindowStrategy()" << std::endl;
}

void CloseWindowStrategy::perform(std::shared_ptr<IEvent> event) {
    controller_->finish();
}
