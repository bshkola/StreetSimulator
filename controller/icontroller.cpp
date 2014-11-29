#include "icontroller.h"
#include <iostream>

Controller::IController::IController()
{
    std::cout << "Hello world in" << std::endl;
}

Controller::IController::~IController()
{
    std::cout << "desk in" << std::endl;
}
