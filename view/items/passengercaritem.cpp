#include "../../view/items/passengercaritem.h"
#include "../mouseeventhandler/trafficparticipansmouseeventhandler.h"
#include "itrafficparticipantitem.h"
#include <QPainter>

PassengerCarItem::PassengerCarItem(const QRectF& rect, QGraphicsItem* parent) :
    ITrafficParticipantItem(rect, parent) {

    selectedColor_ = Qt::red;
    unselectedColor_ = Qt::darkRed;
    color_ = unselectedColor_;

    coordinates_.x = -1;
    coordinates_.y = -1;
}

void PassengerCarItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(QBrush(color_));
    painter->drawRect(this->rect());
}

void PassengerCarItem::setCoordinates(int x, int y) {
    coordinates_.x = x;
    coordinates_.y = y;
}

Coordinates PassengerCarItem::getCoordinates() {
    return coordinates_;
}

bool PassengerCarItem::isOnBoard() {
    if (coordinates_.x == -1 && coordinates_.y == -1) {
        return false;
    }
    return true;
}

int PassengerCarItem::getItemIndex() {
    return item_index_;
}

bool PassengerCarItem::canBeRemoved() {
    return true;
}

IMovableItem* PassengerCarItem::clone() {
    return new PassengerCarItem(this->rect());
}

bool PassengerCarItem::hasDiscretePosition() {
    return true;
}

MouseEventHandler* PassengerCarItem::getMouseEventHandler() {
    return new TrafficParticipansMouseEventHandler();
}

