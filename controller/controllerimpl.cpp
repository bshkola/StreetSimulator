#include "controllerimpl.h"
#include <iostream>
#include "strategy/closewindowstrategy.h"
#include "strategy/itemclickedstrategy.h"

ControllerImpl::ControllerImpl(Model::IModel* model, IView* view) : finish_(false)
{
    map.insert(std::pair<std::string, Strategy*>("WindowClosed", new CloseWindowStrategy(*this)));
    map.insert(std::pair<std::string, Strategy*>("ItemClicked", new ItemClickedStrategy(model, view)));
}

ControllerImpl::~ControllerImpl()
{
    std::cout << "~ControllerImpl" << std::endl;
}

void ControllerImpl::start() {
    while (!finish_) {
        std::cout << "Got it1" << std::endl;
        Event* event = BlockingEventQueue::getInstance().pop();
        std::cout << "Got it2" << std::endl;
        map.at(event->getName())->perform(event);
        std::cout << "Got it3" << std::endl;
    }
    std::cout << "Finished" << std::endl;

}

void ControllerImpl::finish()
{
    finish_ = true;
}
