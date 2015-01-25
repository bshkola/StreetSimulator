//Author: Bogdan Shkola
//Implementation of ControllerImpl class
#include "controllerimpl.h"
#include "strategies/closewindowstrategy.h"
#include "strategies/boardsizechangedstrategy.h"
#include "strategies/streetfieldaddedstrategy.h"
#include "strategies/streetfieldremovedstrategy.h"
#include "strategies/applicationstartedstrategy.h"
#include "strategies/cameraaddedstrategy.h"
#include "strategies/camerareplacedstrategy.h"
#include "strategies/cameraremovedstrategy.h"
#include "strategies/trafficobjectaddedstrategy.h"
#include "strategies/trafficobjectreplacedstrategy.h"
#include "strategies/trafficobjectremovedstrategy.h"
#include "strategies/destinationreplacedstrategy.h"
#include "strategies/startsimulationstrategy.h"
#include "strategies/cameraoptionschangedstrategy.h"

#include "../common/events/applicationstartedevent.h"

ControllerImpl::ControllerImpl(std::shared_ptr<IModel> model, IView* view) : finish_(false) {
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("WindowClosed", std::make_shared<CloseWindowStrategy>(*this)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("BoardSizeChanged", std::make_shared<BoardSizeChangedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("StreetFieldAdded", std::make_shared<StreetFieldAddedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("StreetFieldRemoved", std::make_shared<StreetFieldRemovedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("ApplicationStarted", std::make_shared<ApplicationStartedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("CameraAdded", std::make_shared<CameraAddedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("CameraReplaced", std::make_shared<CameraReplacedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("CameraRemoved", std::make_shared<CameraRemovedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("TrafficObjectAdded", std::make_shared<TrafficObjectAddedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("TrafficObjectReplaced", std::make_shared<TrafficObjectReplacedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("TrafficObjectRemoved", std::make_shared<TrafficObjectRemovedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("DestinationReplaced", std::make_shared<DestinationReplacedStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("StartSimulation", std::make_shared<StartSimulationStrategy>(model, view)));
    map.insert(std::pair<std::string, std::shared_ptr<IStrategy>>("CameraOptionsChanged", std::make_shared<CameraOptionsChangedStrategy>(model, view)));

    BlockingEventQueue::getInstance().push(new ApplicationStartedEvent());
}

ControllerImpl::~ControllerImpl() {
    map.erase(map.begin(), map.end());
}

void ControllerImpl::start() {
    while (!finish_) {
        std::shared_ptr<IEvent> event = BlockingEventQueue::getInstance().pop();
        if (map.find(event->getName()) != map.end()) {
            map.at(event->getName())->perform(event);
        }
    }
}

void ControllerImpl::finish() {
    finish_ = true;
}
