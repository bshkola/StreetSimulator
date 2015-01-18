#ifndef CARREPLACEDSTRATEGY_H
#define CARREPLACEDSTRATEGY_H

#include "istrategy.h"

class TrafficObjectReplacedStrategy : public IStrategy
{
public:
    TrafficObjectReplacedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(IEvent* event);
    virtual ~TrafficObjectReplacedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CARREPLACEDSTRATEGY_H
