#include "itemclickedstrategy.h"
#include "iostream"

ItemClickedStrategy::ItemClickedStrategy(Model::IModel* model, IView* view) : model_(model), view_(view)
{
}

void ItemClickedStrategy::perform(IEvent* event)
{
    std::cout << "ItemClickedStrategy" << std::endl;
}

std::string ItemClickedStrategy::getName()
{
    return "ItemClicked";
}
