#include "controllerimpl.h"
#include <iostream>

Controller::ControllerImpl::ControllerImpl()
{
    BlockingEventQueue::getInstance();

}

Controller::ControllerImpl::~ControllerImpl()
{
}

void Controller::ControllerImpl::start() {
    for (int i = 0; i < 100; ++i) {
//    while (true) {
        std::cout << "1";
    }
}
