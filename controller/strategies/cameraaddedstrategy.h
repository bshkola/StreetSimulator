//Author: Bogdan Shkola
//Strategy handling camera adding
#ifndef CAMERAADDEDSTRATEGY_H
#define CAMERAADDEDSTRATEGY_H

#include "istrategy.h"

class CameraAddedStrategy : public IStrategy
{
public:
    CameraAddedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~CameraAddedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CAMERAADDEDSTRATEGY_H
