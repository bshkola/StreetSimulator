#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include "iostream"
#include "../../common/events/ievent.h"

class IStrategy
{
public:
    IStrategy();
    virtual void perform(IEvent* event) = 0;
};

#endif // ISTRATEGY_H
