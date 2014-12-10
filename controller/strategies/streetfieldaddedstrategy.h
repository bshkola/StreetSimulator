#ifndef STREETFIELDADDEDSTRATEGY_H
#define STREETFIELDADDEDSTRATEGY_H

#include "istrategy.h"

class StreetFieldAddedStrategy : public IStrategy
{
public:
    StreetFieldAddedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // STREETFIELDADDEDSTRATEGY_H
