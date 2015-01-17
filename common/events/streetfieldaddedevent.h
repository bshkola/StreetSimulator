#ifndef STREETFIELDADDEDEVENT_H
#define STREETFIELDADDEDEVENT_H

#include "ievent.h"
#include "../../common/types.h"

class StreetFieldAddedEvent : public IEvent
{
public:
    StreetFieldAddedEvent(Coordinates coordinates);
    std::string getName();
    Coordinates getCoordinates();
private:
    Coordinates coordinates_;
};

#endif // STREETFIELDADDEDEVENT_H
