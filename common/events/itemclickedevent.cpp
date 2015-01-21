#include "itemclickedevent.h"
#include "ievent.h"

ItemClickedEvent::ItemClickedEvent(Coordinates coordinates) : coordinates_(coordinates) {
}

std::string ItemClickedEvent::getName() {
    return "ItemClicked";
}

Coordinates ItemClickedEvent::getCoordinates() {
    return coordinates_;
}
