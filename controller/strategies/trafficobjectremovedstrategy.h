#ifndef CARREMOVEDSTRATEGY_H
#define CARREMOVEDSTRATEGY_H

#include "istrategy.h"

class TrafficObjectRemovedStrategy : public IStrategy
{
public:
    TrafficObjectRemovedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // CARREMOVEDSTRATEGY_H
