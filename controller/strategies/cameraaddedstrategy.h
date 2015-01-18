#ifndef CAMERAADDEDSTRATEGY_H
#define CAMERAADDEDSTRATEGY_H

#include "istrategy.h"

class CameraAddedStrategy : public IStrategy
{
public:
    CameraAddedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // CAMERAADDEDSTRATEGY_H
