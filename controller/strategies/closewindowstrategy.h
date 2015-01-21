#ifndef CLOSEWINDOWSTRATEGY_H
#define CLOSEWINDOWSTRATEGY_H

#include "istrategy.h"
#include "../../controller/controllerimpl.h"

class CloseWindowStrategy : public IStrategy
{
public:
    CloseWindowStrategy(IController& controller);
    void perform(std::shared_ptr<IEvent> event);
    virtual ~CloseWindowStrategy();

private:
    IController* controller_;
};

#endif // CLOSEWINDOWSTRATEGY_H
