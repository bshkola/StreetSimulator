//Author: Bogdan Shkola
//Representing the interface of main controller of application.
#ifndef ICONTROLLER_H
#define ICONTROLLER_H

class IController {
public:
    IController() {}
    virtual ~IController() {}

    //Starts the controller loop
    virtual void start() = 0;

    //Shuts down the controller
    virtual void finish() = 0;
};

#endif // ICONTROLLER_H
