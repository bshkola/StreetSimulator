#ifndef CAMERAREPLACEDSTRATEGY_H
#define CAMERAREPLACEDSTRATEGY_H

#include "istrategy.h"

class CameraReplacedStrategy : public IStrategy
{
public:
    CameraReplacedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // CAMERAREPLACEDSTRATEGY_H
