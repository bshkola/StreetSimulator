#ifndef CARREPLACEDSTRATEGY_H
#define CARREPLACEDSTRATEGY_H

#include "istrategy.h"

class TrafficObjectReplacedStrategy : public IStrategy
{
public:
    TrafficObjectReplacedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // CARREPLACEDSTRATEGY_H
