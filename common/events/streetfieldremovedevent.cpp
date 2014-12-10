#include "streetfieldremovedevent.h"

StreetFieldRemovedEvent::StreetFieldRemovedEvent(Coordinates coordinates) : coordinates_(coordinates)
{
}

std::string StreetFieldRemovedEvent::getName()
{
    return "StreetFieldRemoved";
}

Coordinates StreetFieldRemovedEvent::getCoordinates()
{
    return coordinates_;
}
