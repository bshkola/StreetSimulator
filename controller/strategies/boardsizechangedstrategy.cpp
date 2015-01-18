#include "../../controller/strategies/boardsizechangedstrategy.h"

BoardSizeChangedStrategy::BoardSizeChangedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view)
{
}

BoardSizeChangedStrategy::~BoardSizeChangedStrategy() {
}

void BoardSizeChangedStrategy::perform(IEvent* event)
{
    std::cout << "BoardSizeChanged" << std::endl;
}
