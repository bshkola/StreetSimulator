//Author: Bogdan Shkola
//Implementation of ApplicationStartedStrategy class
#include "../../controller/strategies/applicationstartedstrategy.h"

ApplicationStartedStrategy::ApplicationStartedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

ApplicationStartedStrategy::~ApplicationStartedStrategy() {
}

void ApplicationStartedStrategy::perform(std::shared_ptr<IEvent> event) {
    view_->showBoard(model_->getBoard());
}
