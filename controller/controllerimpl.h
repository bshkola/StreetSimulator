//Author: Bogdan Shkola
//Representing implementation of the main controller of the application.
#ifndef CONTROLLERIMPL_H
#define CONTROLLERIMPL_H

#include "icontroller.h"
#include "blockingqueue.h"
#include "../common/events/ievent.h"
#include "../model/imodel.h"
#include "../view/iview.h"
#include "strategies/istrategy.h"
#include <memory>

class ControllerImpl : public IController
{
public:
    ControllerImpl(std::shared_ptr<IModel> model, IView* view);
    virtual ~ControllerImpl();

    //Inherinted methods
    void start();
    void finish();

private:
    //Flag sygnalizing finish of the loop
    bool finish_;
    //Strategy maps which defines reaction on different events
    std::map<std::string, std::shared_ptr<IStrategy>> map;
};

#endif // CONTROLLERIMPL_H
