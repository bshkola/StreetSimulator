//Author: Bogdan Shkola
//Representing the interface of main controller of application.

#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <QObject>

class IController : public QObject
{
public:
    IController();
    virtual ~IController();
    virtual void start() = 0; // stars the controller loop
    virtual void finish() = 0; // shuts down the controller
};

#endif // ICONTROLLER_H
