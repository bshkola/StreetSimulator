#ifndef ITEMCLICKEDSTRATEGY_H
#define ITEMCLICKEDSTRATEGY_H

#include "istrategy.h"
#include <string>

class ItemClickedStrategy : public IStrategy
{
public:
    ItemClickedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // ITEMCLICKEDSTRATEGY_H
