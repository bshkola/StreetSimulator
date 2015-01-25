//Author: Bogdan Shkola
//Event got when street field is added
#ifndef STREETFIELDADDEDEVENT_H
#define STREETFIELDADDEDEVENT_H

#include "ievent.h"
#include "../../common/types.h"

class StreetFieldAddedEvent : public IEvent
{
public:
    StreetFieldAddedEvent(Position coordinates);
    std::string getName();
    Position getCoordinates();
private:
    Position coordinates_;
};

#endif // STREETFIELDADDEDEVENT_H
