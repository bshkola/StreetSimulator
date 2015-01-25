//Author: Bogdan Shkola
//Strategy handling destination replacing
#ifndef DESTINATIONREPLACEDSTRATEGY_H
#define DESTINATIONREPLACEDSTRATEGY_H

#include "istrategy.h"

class DestinationReplacedStrategy : public IStrategy
{
public:
    DestinationReplacedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~DestinationReplacedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // DESTINATIONREPLACEDSTRATEGY_H
