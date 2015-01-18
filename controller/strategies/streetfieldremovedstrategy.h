#ifndef STREETFIELDREMOVEDSTRATEGY_H
#define STREETFIELDREMOVEDSTRATEGY_H

#include "istrategy.h"

class StreetFieldRemovedStrategy : public IStrategy
{
public:
    StreetFieldRemovedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(IEvent* event);
    virtual ~StreetFieldRemovedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // STREETFIELDREMOVEDSTRATEGY_H
