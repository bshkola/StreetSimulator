#ifndef CARADDEDSTRATEGY_H
#define CARADDEDSTRATEGY_H

#include "istrategy.h"

class TrafficObjectAddedStrategy : public IStrategy
{
public:
    TrafficObjectAddedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(IEvent* event);
    virtual ~TrafficObjectAddedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CARADDEDSTRATEGY_H
