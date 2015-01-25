//Author: Bogdan Shkola
//Strategy handling closing the window
#ifndef CLOSEWINDOWSTRATEGY_H
#define CLOSEWINDOWSTRATEGY_H

#include "istrategy.h"
#include "../../controller/controllerimpl.h"

class CloseWindowStrategy : public IStrategy
{
public:
    CloseWindowStrategy(IController& controller);
    virtual ~CloseWindowStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    IController* controller_;
};

#endif // CLOSEWINDOWSTRATEGY_H
