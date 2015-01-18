#include "../../controller/strategies/itemclickedstrategy.h"

ItemClickedStrategy::ItemClickedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view)
{
}

ItemClickedStrategy::~ItemClickedStrategy() {
}

void ItemClickedStrategy::perform(IEvent* event)
{
    std::cout << "ItemClickedStrategy" << std::endl;
}
