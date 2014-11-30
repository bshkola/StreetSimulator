#include "itemclickedevent.h"
#include "event.h"

ItemClickedEvent::ItemClickedEvent() {
}

ItemClickedEvent::ItemClickedEvent(Coordinates coordinates) {
    this->coordinates = coordinates;
}
