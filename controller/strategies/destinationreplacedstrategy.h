#ifndef DESTINATIONREPLACEDSTRATEGY_H
#define DESTINATIONREPLACEDSTRATEGY_H

#include "istrategy.h"

class DestinationReplacedStrategy : public IStrategy
{
public:
    DestinationReplacedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(IEvent* event);
    virtual ~DestinationReplacedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // DESTINATIONREPLACEDSTRATEGY_H
