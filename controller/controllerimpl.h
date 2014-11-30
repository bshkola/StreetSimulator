#ifndef CONTROLLERIMPL_H
#define CONTROLLERIMPL_H

#include "icontroller.h"
#include "blockingqueue.h"
#include "../common/event.h"

namespace Controller {

class ControllerImpl : public IController
{
public:
    ControllerImpl();
    virtual ~ControllerImpl();

    void start();
};

}
#endif // CONTROLLERIMPL_H
