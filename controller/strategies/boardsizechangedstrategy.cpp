#include "boardsizechangedstrategy.h"

BoardSizeChangedStrategy::BoardSizeChangedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void BoardSizeChangedStrategy::perform(IEvent* event)
{
    std::cout << "BoardSizeChanged" << std::endl;
}
