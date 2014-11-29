#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <QObject>

namespace Controller
{

class IController : public QObject
{
public:
    IController();
    virtual ~IController();
};

}

#endif // ICONTROLLER_H
