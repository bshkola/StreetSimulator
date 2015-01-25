//Author: Bogdan Shkola
//Event got when street field is removed
#ifndef STREETFIELDREMOVEDEVENT_H
#define STREETFIELDREMOVEDEVENT_H

#include "ievent.h"
#include "../../common/types.h"

class StreetFieldRemovedEvent : public IEvent
{
public:
    StreetFieldRemovedEvent(Position coordinates);
    std::string getName();
    Position getCoordinates();
private:
    Position coordinates_;
};

#endif // STREETFIELDREMOVEDEVENT_H
