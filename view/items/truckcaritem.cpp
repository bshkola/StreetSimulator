#include "../../view/items/truckcaritem.h"
#include "../mouseeventhandler/trafficparticipansmouseeventhandler.h"
#include "itrafficparticipantitem.h"
#include <QPainter>

TruckCarItem::TruckCarItem(const QRectF& rect, QGraphicsItem* parent) :
    ITrafficParticipantItem(rect, parent) {

    selectedColor_ = Qt::cyan;
    unselectedColor_ = Qt::darkCyan;
}

ObjectType TruckCarItem::getTrafficObjectType() {
    return trafficObjectType_;
}

IMovableItem* TruckCarItem::clone() {
    return new TruckCarItem(this->rect());
}

MouseEventHandler* TruckCarItem::getMouseEventHandler() {
    return TrafficParticipansMouseEventHandler::getInstance();
}

