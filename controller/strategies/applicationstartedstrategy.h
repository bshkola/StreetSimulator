#ifndef APPLICATIONSTARTEDSTRATEGY_H
#define APPLICATIONSTARTEDSTRATEGY_H

#include "istrategy.h"

class ApplicationStartedStrategy : public IStrategy
{
public:
    ApplicationStartedStrategy(IModel* model, IView* view);

    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // APPLICATIONSTARTEDSTRATEGY_H
