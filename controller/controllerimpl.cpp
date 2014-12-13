#include "controllerimpl.h"
#include <iostream>
#include "strategies/closewindowstrategy.h"
#include "strategies/itemclickedstrategy.h"
#include "strategies/boardsizechangedstrategy.h"
#include "strategies/streetfieldaddedstrategy.h"
#include "strategies/streetfieldremovedstrategy.h"
#include "strategies/applicationstartedstrategy.h"

#include "../common/events/applicationstartedevent.h"

ControllerImpl::ControllerImpl(IModel* model, IView* view) : finish_(false)
{
    map.insert(std::pair<std::string, IStrategy*>("WindowClosed", new CloseWindowStrategy(*this)));
    map.insert(std::pair<std::string, IStrategy*>("ItemClicked", new ItemClickedStrategy(model, view)));
    map.insert(std::pair<std::string, IStrategy*>("BoardSizeChanged", new BoardSizeChangedStrategy(model, view)));
    map.insert(std::pair<std::string, IStrategy*>("StreetFieldAdded", new StreetFieldAddedStrategy(model, view)));
    map.insert(std::pair<std::string, IStrategy*>("StreetFieldRemoved", new StreetFieldRemovedStrategy(model, view)));
    map.insert(std::pair<std::string, IStrategy*>("ApplicationStarted", new ApplicationStartedStrategy(model, view)));

    BlockingEventQueue::getInstance().push(new ApplicationStartedEvent());
}

ControllerImpl::~ControllerImpl()
{
    std::cout << "~ControllerImpl" << std::endl;
}

void ControllerImpl::start() {
    while (!finish_) {
        IEvent* event = BlockingEventQueue::getInstance().pop();
        std::cout << "Got new event" << std::endl;
        if (map.find(event->getName()) != map.end()) {
            map.at(event->getName())->perform(event);
            std::cout << "Performed" << std::endl;
        }
        else {
            std::cout << "Event is bad" << std::endl;
        }
    }
    std::cout << "Finished" << std::endl;
}

void ControllerImpl::finish()
{
    finish_ = true;
}
