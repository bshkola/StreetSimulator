#ifndef ITEMCLICKEDEVENT_H
#define ITEMCLICKEDEVENT_H

#include "ievent.h"
#include "../coordinates.h"

class ItemClickedEvent : public IEvent
{
public:
    ItemClickedEvent();
    ItemClickedEvent(Coordinates coordinates);

    std::string getName();
    Coordinates getCoordinates() { return coordinates; }
private:
    Coordinates coordinates;
};

#endif // ITEMCLICKEDEVENT_H
