//Author: Bogdan Shkola
//Strategy handling traffic object removing
#ifndef CARREMOVEDSTRATEGY_H
#define CARREMOVEDSTRATEGY_H

#include "istrategy.h"

class TrafficObjectRemovedStrategy : public IStrategy
{
public:
    TrafficObjectRemovedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~TrafficObjectRemovedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CARREMOVEDSTRATEGY_H
