//Author: Bogdan Shkola
//Strategy handling street field removing
#ifndef STREETFIELDREMOVEDSTRATEGY_H
#define STREETFIELDREMOVEDSTRATEGY_H

#include "istrategy.h"

class StreetFieldRemovedStrategy : public IStrategy
{
public:
    StreetFieldRemovedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~StreetFieldRemovedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // STREETFIELDREMOVEDSTRATEGY_H
