#include "../../controller/strategies/streetfieldaddedstrategy.h"
#include "../../common/events/streetfieldaddedevent.h"

StreetFieldAddedStrategy::StreetFieldAddedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

StreetFieldAddedStrategy::~StreetFieldAddedStrategy() {
}

void StreetFieldAddedStrategy::perform(std::shared_ptr<IEvent> event) {
    StreetFieldAddedEvent* streetFieldAddedEvent = static_cast<StreetFieldAddedEvent*>(event.get());
    model_->addStreet(streetFieldAddedEvent->getCoordinates());
}
