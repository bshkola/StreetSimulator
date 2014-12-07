#ifndef CONTROLLERIMPL_H
#define CONTROLLERIMPL_H

#include "icontroller.h"
#include "blockingqueue.h"
#include "../common/events/ievent.h"
#include "strategies/istrategy.h"
#include "../model/imodel.h"
#include "../view/iview.h"

class ControllerImpl : public IController
{
public:
    ControllerImpl(Model::IModel* model, IView* view);
    virtual ~ControllerImpl();

    void start();
    void finish();

private:
    bool finish_;
    std::map<std::string, IStrategy*> map;
};

#endif // CONTROLLERIMPL_H
