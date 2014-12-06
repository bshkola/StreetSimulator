#ifndef ITEMCLICKEDSTRATEGY_H
#define ITEMCLICKEDSTRATEGY_H

#include "strategy.h"
#include <string>
#include "../../model/imodel.h"
#include "../../view/iview.h"

class ItemClickedStrategy : public Strategy
{
public:
    ItemClickedStrategy(Model::IModel* model, IView* view);
    void perform(Event* event);
    std::string getName();

private:
    Model::IModel* model_;
    IView* view_;
};

#endif // ITEMCLICKEDSTRATEGY_H
