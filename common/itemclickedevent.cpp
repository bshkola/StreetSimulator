#include "itemclickedevent.h"
#include "event.h"

ItemClickedEvent::ItemClickedEvent() {
}

ItemClickedEvent::ItemClickedEvent(Coordinates coordinates) {
    this->coordinates = coordinates;
}


std::string ItemClickedEvent::getName()
{
    return "ItemClicked";
}
