//Author: Bogdan Shkola
//Strategy handling camera replacing
#ifndef CAMERAREPLACEDSTRATEGY_H
#define CAMERAREPLACEDSTRATEGY_H

#include "istrategy.h"

class CameraReplacedStrategy : public IStrategy
{
public:
    CameraReplacedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~CameraReplacedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CAMERAREPLACEDSTRATEGY_H
