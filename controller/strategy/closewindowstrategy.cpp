#include "closewindowstrategy.h"
#include "iostream"

CloseWindowStrategy::CloseWindowStrategy(IController& controller) : controller_(&controller)
{
}

void CloseWindowStrategy::perform(Event* event)
{
    controller_->finish();
    std::cout << "CloseWindowStrategy" << std::endl;
}

std::string CloseWindowStrategy::getName()
{
    return "CloseWindow";
}
