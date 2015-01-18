#ifndef CARREMOVEDSTRATEGY_H
#define CARREMOVEDSTRATEGY_H

#include "istrategy.h"

class TrafficObjectRemovedStrategy : public IStrategy
{
public:
    TrafficObjectRemovedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(IEvent* event);
    virtual ~TrafficObjectRemovedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CARREMOVEDSTRATEGY_H
