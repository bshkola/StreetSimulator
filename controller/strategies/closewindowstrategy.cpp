#include "../../controller/strategies/closewindowstrategy.h"

CloseWindowStrategy::CloseWindowStrategy(IController& controller) : controller_(&controller)
{
    std::cout << "CloseWindowStrategy()" << std::endl;
}

CloseWindowStrategy::~CloseWindowStrategy()
{
}

void CloseWindowStrategy::perform(IEvent* event)
{
    controller_->finish();
    std::cout << "CloseWindowStrategy" << std::endl;
}
