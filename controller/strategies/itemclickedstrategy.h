#ifndef ITEMCLICKEDSTRATEGY_H
#define ITEMCLICKEDSTRATEGY_H

#include "istrategy.h"

class ItemClickedStrategy : public IStrategy
{
public:
    ItemClickedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(IEvent* event);
    virtual ~ItemClickedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // ITEMCLICKEDSTRATEGY_H
