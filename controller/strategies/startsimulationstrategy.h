#ifndef STARTSIMULATIONSTRATEGY_H
#define STARTSIMULATIONSTRATEGY_H

#include "istrategy.h"

class StartSimulationStrategy : public IStrategy
{
public:
    StartSimulationStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // STARTSIMULATIONSTRATEGY_H
