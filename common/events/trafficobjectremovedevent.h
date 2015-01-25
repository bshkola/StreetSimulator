//Author: Bogdan Shkola
//Event got when traffic object is removed
#ifndef CARREMOVEDEVENT_H
#define CARREMOVEDEVENT_H

#include "ievent.h"


class TrafficObjectRemovedEvent : public IEvent
{
public:
    TrafficObjectRemovedEvent(int id);
    std::string getName();
    int getId();

private:
    int id_;
};

#endif // CARREMOVEDEVENT_H
