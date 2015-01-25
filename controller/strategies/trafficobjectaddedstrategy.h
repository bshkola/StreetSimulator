//Author: Bogdan Shkola
//Strategy handling traffic object adding
#ifndef TRAFFICOBJECTADDEDSTRATEGY_H
#define TRAFFICOBJECTADDEDSTRATEGY_H

#include "istrategy.h"

class TrafficObjectAddedStrategy : public IStrategy
{
public:
    TrafficObjectAddedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~TrafficObjectAddedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // TRAFFICOBJECTADDEDSTRATEGY_H
