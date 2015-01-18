#include "../../controller/strategies/applicationstartedstrategy.h"

ApplicationStartedStrategy::ApplicationStartedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

ApplicationStartedStrategy::~ApplicationStartedStrategy() {
}

void ApplicationStartedStrategy::perform(IEvent *event) {
    view_->showBoard(model_->getBoard());
    //model_->getBoard();
}
