#include "../../view/items/passengercaritem.h"
#include "../mouseeventhandler/trafficparticipansmouseeventhandler.h"
#include "itrafficparticipantitem.h"
#include <QPainter>

PassengerCarItem::PassengerCarItem(const QRectF& rect, QGraphicsItem* parent) :
    ITrafficParticipantItem(rect, parent) {

    selectedColor_ = Qt::red;
    unselectedColor_ = Qt::darkRed;
}

ObjectType PassengerCarItem::getTrafficObjectType() {
    return trafficObjectType_;
}

IMovableItem* PassengerCarItem::clone() {
    return new PassengerCarItem(this->rect());
}

MouseEventHandler* PassengerCarItem::getMouseEventHandler() {
    return TrafficParticipansMouseEventHandler::getInstance();
}

