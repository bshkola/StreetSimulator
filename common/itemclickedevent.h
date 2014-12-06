#ifndef ITEMCLICKEDEVENT_H
#define ITEMCLICKEDEVENT_H

#include "event.h"
#include "coordinates.h"

class ItemClickedEvent : public Event
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
