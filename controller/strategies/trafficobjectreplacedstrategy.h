//Author: Bogdan Shkola
//Strategy handling traffic object replacing
#ifndef CARREPLACEDSTRATEGY_H
#define CARREPLACEDSTRATEGY_H

#include "istrategy.h"

class TrafficObjectReplacedStrategy : public IStrategy
{
public:
    TrafficObjectReplacedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~TrafficObjectReplacedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CARREPLACEDSTRATEGY_H
