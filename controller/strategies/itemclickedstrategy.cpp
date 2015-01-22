#include "../../controller/strategies/itemclickedstrategy.h"

ItemClickedStrategy::ItemClickedStrategy(std::shared_ptr<IModel> model, IView* view) : model_(model), view_(view) {
}

ItemClickedStrategy::~ItemClickedStrategy() {
    std::cout << "~ItemClickedStrategy()" << std::endl;
}

void ItemClickedStrategy::perform(std::shared_ptr<IEvent> event) {
    std::cout << "ItemClickedStrategy" << std::endl;
}
