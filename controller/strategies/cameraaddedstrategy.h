#ifndef CAMERAADDEDSTRATEGY_H
#define CAMERAADDEDSTRATEGY_H

#include "istrategy.h"

class CameraAddedStrategy : public IStrategy
{
public:
    CameraAddedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(IEvent* event);
    virtual ~CameraAddedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CAMERAADDEDSTRATEGY_H
