#ifndef STARTSIMULATIONSTRATEGY_H
#define STARTSIMULATIONSTRATEGY_H

#include "istrategy.h"

class StartSimulationStrategy : public IStrategy
{
public:
    StartSimulationStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(std::shared_ptr<IEvent> event);
    virtual ~StartSimulationStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // STARTSIMULATIONSTRATEGY_H
