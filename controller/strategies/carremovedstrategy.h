#ifndef CARREMOVEDSTRATEGY_H
#define CARREMOVEDSTRATEGY_H

#include "istrategy.h"

class CarRemovedStrategy : public IStrategy
{
public:
    CarRemovedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // CARREMOVEDSTRATEGY_H
