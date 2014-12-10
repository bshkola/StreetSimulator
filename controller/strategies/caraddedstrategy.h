#ifndef CARADDEDSTRATEGY_H
#define CARADDEDSTRATEGY_H

#include "istrategy.h"

class CarAddedStrategy : public IStrategy
{
public:
    CarAddedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // CARADDEDSTRATEGY_H
