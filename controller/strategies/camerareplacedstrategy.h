#ifndef CAMERAREPLACEDSTRATEGY_H
#define CAMERAREPLACEDSTRATEGY_H

#include "istrategy.h"

class CameraReplacedStrategy : public IStrategy
{
public:
    CameraReplacedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(IEvent* event);
    virtual ~CameraReplacedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CAMERAREPLACEDSTRATEGY_H
