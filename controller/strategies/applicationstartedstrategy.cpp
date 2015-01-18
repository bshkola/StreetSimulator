#include "../../controller/strategies/applicationstartedstrategy.h"

ApplicationStartedStrategy::ApplicationStartedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void ApplicationStartedStrategy::perform(IEvent *event) {
    view_->showBoard(model_->getBoard());
    //model_->getBoard();
}
