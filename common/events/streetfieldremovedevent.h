#ifndef STREETFIELDREMOVEDEVENT_H
#define STREETFIELDREMOVEDEVENT_H

#include "ievent.h"
#include "../../common/types.h"

class StreetFieldRemovedEvent : public IEvent
{
public:
    StreetFieldRemovedEvent(Coordinates coordinates);
    std::string getName();
    Coordinates getCoordinates();
private:
    Coordinates coordinates_;
};

#endif // STREETFIELDREMOVEDEVENT_H
