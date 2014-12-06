#ifndef STRATEGY_H
#define STRATEGY_H

#include "../../common/event.h"

class Strategy
{
public:
    Strategy();
    virtual void perform(Event* event) = 0;
};

#endif // STRATEGY_H
