#include "closewindowstrategy.h"

CloseWindowStrategy::CloseWindowStrategy(IController& controller) : controller_(&controller)
{
}

void CloseWindowStrategy::perform(IEvent* event)
{
    controller_->finish();
    std::cout << "CloseWindowStrategy" << std::endl;
}

std::string CloseWindowStrategy::getName()
{
    return "CloseWindow";
}
