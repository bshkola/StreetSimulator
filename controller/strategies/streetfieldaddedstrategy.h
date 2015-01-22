#ifndef STREETFIELDADDEDSTRATEGY_H
#define STREETFIELDADDEDSTRATEGY_H

#include "istrategy.h"

class StreetFieldAddedStrategy : public IStrategy
{
public:
    StreetFieldAddedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(std::shared_ptr<IEvent> event);
    virtual ~StreetFieldAddedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // STREETFIELDADDEDSTRATEGY_H
