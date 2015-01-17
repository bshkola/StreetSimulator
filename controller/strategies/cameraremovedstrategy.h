#ifndef CAMERAREMOVEDSTRATEGY_H
#define CAMERAREMOVEDSTRATEGY_H

#include "istrategy.h"

class CameraRemovedStrategy : public IStrategy
{
public:
    CameraRemovedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // CAMERAREMOVEDSTRATEGY_H
