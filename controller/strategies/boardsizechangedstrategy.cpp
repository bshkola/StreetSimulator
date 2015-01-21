#include "../../controller/strategies/boardsizechangedstrategy.h"
#include "../../common/events/boardsizechangedevent.h"

BoardSizeChangedStrategy::BoardSizeChangedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}
void BoardSizeChangedStrategy::perform(IEvent* event)
{
    BoardSizeChangedEvent* boardSizeChangedEvent = static_cast<BoardSizeChangedEvent*>(event);
    model_->setBoardSize(boardSizeChangedEvent->getBoardSize());
    view_->createBoard(model_->getBoardSize());
    std::cout << "BoardSizeChanged" << std::endl;
}
