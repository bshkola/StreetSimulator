//Author: Bogdan Shkola
//Strategy handling start of the simulation
#ifndef STARTSIMULATIONSTRATEGY_H
#define STARTSIMULATIONSTRATEGY_H

#include "istrategy.h"

class StartSimulationStrategy : public IStrategy
{
public:
    StartSimulationStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~StartSimulationStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // STARTSIMULATIONSTRATEGY_H
