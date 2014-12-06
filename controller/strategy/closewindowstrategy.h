#ifndef CLOSEWINDOWSTRATEGY_H
#define CLOSEWINDOWSTRATEGY_H

#include "strategy.h"
#include <string>
#include "../../controller/controllerimpl.h"

class CloseWindowStrategy : public Strategy
{
public:
    CloseWindowStrategy(IController& controller);
    void perform(Event* event);
    std::string getName();

private:
    IController* controller_;
};

#endif // CLOSEWINDOWSTRATEGY_H
