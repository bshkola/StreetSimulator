#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include "iostream"
#include "../../common/events/ievent.h"
#include "../../model/imodel.h"
#include "../../view/iview.h"

class IStrategy
{
public:
    IStrategy();
    virtual void perform(IEvent* event) = 0;
};

#endif // ISTRATEGY_H
