#include "itemclickedevent.h"
#include "ievent.h"

ItemClickedEvent::ItemClickedEvent() {
}

ItemClickedEvent::ItemClickedEvent(Coordinates coordinates) {
    this->coordinates = coordinates;
}


std::string ItemClickedEvent::getName()
{
    return "ItemClicked";
}
