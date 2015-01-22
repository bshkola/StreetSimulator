#ifndef CAMERAREMOVEDSTRATEGY_H
#define CAMERAREMOVEDSTRATEGY_H

#include "istrategy.h"

class CameraRemovedStrategy : public IStrategy
{
public:
    CameraRemovedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(std::shared_ptr<IEvent> event);
    virtual ~CameraRemovedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CAMERAREMOVEDSTRATEGY_H
