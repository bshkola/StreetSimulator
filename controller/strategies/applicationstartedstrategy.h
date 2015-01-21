#ifndef APPLICATIONSTARTEDSTRATEGY_H
#define APPLICATIONSTARTEDSTRATEGY_H

#include "istrategy.h"

class ApplicationStartedStrategy : public IStrategy
{
public:
    ApplicationStartedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(std::shared_ptr<IEvent> event);
    virtual ~ApplicationStartedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // APPLICATIONSTARTEDSTRATEGY_H
