#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <QObject>

class IController : public QObject
{
public:
    IController();
    virtual ~IController();
    virtual void start() = 0;
    virtual void finish() = 0;
};

#endif // ICONTROLLER_H
