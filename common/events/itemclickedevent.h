#ifndef ITEMCLICKEDEVENT_H
#define ITEMCLICKEDEVENT_H

#include "ievent.h"
#include "../types.h"

class ItemClickedEvent : public IEvent
{
public:
    ItemClickedEvent(Coordinates coordinates);

    std::string getName();
    Coordinates getCoordinates();
private:
    Coordinates coordinates_;
};

#endif // ITEMCLICKEDEVENT_H
