#ifndef DESTINATIONREPLACEDSTRATEGY_H
#define DESTINATIONREPLACEDSTRATEGY_H

#include "istrategy.h"

class DestinationReplacedStrategy : public IStrategy
{
public:
    DestinationReplacedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // DESTINATIONREPLACEDSTRATEGY_H
