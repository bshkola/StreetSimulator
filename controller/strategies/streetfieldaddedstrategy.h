//Author: Bogdan Shkola
//Strategy handling street field adding
#ifndef STREETFIELDADDEDSTRATEGY_H
#define STREETFIELDADDEDSTRATEGY_H

#include "istrategy.h"

class StreetFieldAddedStrategy : public IStrategy
{
public:
    StreetFieldAddedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~StreetFieldAddedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // STREETFIELDADDEDSTRATEGY_H
