#ifndef STREETFIELDREMOVEDSTRATEGY_H
#define STREETFIELDREMOVEDSTRATEGY_H

#include "istrategy.h"

class StreetFieldRemovedStrategy : public IStrategy
{
public:
    StreetFieldRemovedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // STREETFIELDREMOVEDSTRATEGY_H
