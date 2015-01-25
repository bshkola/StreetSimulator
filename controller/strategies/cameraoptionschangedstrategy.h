//Author: Bogdan Shkola
//Strategy handling camera options chenging
#ifndef CAMERAOPTIONSCHANGEDSTRATEGY_H
#define CAMERAOPTIONSCHANGEDSTRATEGY_H

#include "istrategy.h"

class CameraOptionsChangedStrategy : public IStrategy
{
public:
    CameraOptionsChangedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~CameraOptionsChangedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // CAMERAOPTIONSCHANGEDSTRATEGY_H
