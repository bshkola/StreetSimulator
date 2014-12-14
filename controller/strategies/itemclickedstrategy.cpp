#include "itemclickedstrategy.h"

ItemClickedStrategy::ItemClickedStrategy(IModel* model, IView* view) : model_(model), view_(view)
{
}

void ItemClickedStrategy::perform(IEvent* event)
{
    std::cout << "ItemClickedStrategy" << std::endl;
}
