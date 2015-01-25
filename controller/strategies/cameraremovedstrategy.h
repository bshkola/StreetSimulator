//Author: Bogdan Shkola
//Strategy handling camera removing
#ifndef CAMERAREMOVEDSTRATEGY_H
#define CAMERAREMOVEDSTRATEGY_H

#include "istrategy.h"

class CameraRemovedStrategy : public IStrategy
{
public:
    CameraRemovedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~CameraRemovedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CAMERAREMOVEDSTRATEGY_H
