//Author: Bogdan Shkola
//Implementation of BoardSizeChangedStrategy class
#include "../../controller/strategies/boardsizechangedstrategy.h"
#include "../../common/events/boardsizechangedevent.h"

BoardSizeChangedStrategy::BoardSizeChangedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

BoardSizeChangedStrategy::~BoardSizeChangedStrategy() {
}

void BoardSizeChangedStrategy::perform(std::shared_ptr<IEvent> event) {
    BoardSizeChangedEvent* boardSizeChangedEvent = static_cast<BoardSizeChangedEvent*>(event.get());
    model_->resizeBoard(boardSizeChangedEvent->getBoardSize());
}
