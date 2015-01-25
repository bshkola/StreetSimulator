//Author: Bogdan Shkola
//Implementation of StreetFieldRemovedStrategy class
#include "../../controller/strategies/streetfieldremovedstrategy.h"
#include "../../common/events/streetfieldremovedevent.h"

StreetFieldRemovedStrategy::StreetFieldRemovedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

StreetFieldRemovedStrategy::~StreetFieldRemovedStrategy() {
}

void StreetFieldRemovedStrategy::perform(std::shared_ptr<IEvent> event) {
    StreetFieldRemovedEvent* streetFieldRemovedEvent = static_cast<StreetFieldRemovedEvent*>(event.get());
    model_->removeStreet(streetFieldRemovedEvent->getCoordinates());
}
