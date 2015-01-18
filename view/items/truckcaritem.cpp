#include "../../view/items/truckcaritem.h"
#include "../mouseeventhandler/trafficparticipansmouseeventhandler.h"
#include "itrafficparticipantitem.h"
#include <QPainter>

/*TruckCarItem::TruckCarItem(int itemIndex, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent) :
    IMovableItem(x + width / 4, y + height / 4, width / 2, height / 2, parent) {
    color_ = Qt::blue;
    coordinates_.x = -1;
    coordinates_.y = -1;
    item_index_ = itemIndex;
}*/

TruckCarItem::TruckCarItem(const QRectF& rect, QGraphicsItem* parent) :
    ITrafficParticipantItem(rect, parent) {

    selectedColor_ = Qt::blue;
    unselectedColor_ = Qt::darkBlue;
    color_ = unselectedColor_;

    coordinates_.first = -1;
    coordinates_.second = -1;
}

void TruckCarItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(QBrush(color_));
    painter->drawRect(this->rect());
}

void TruckCarItem::setCoordinates(int x, int y) {
    coordinates_.first = x;
    coordinates_.second = y;
}

Coordinates TruckCarItem::getCoordinates() {
    return coordinates_;
}

bool TruckCarItem::isOnBoard() {
    if (coordinates_.first == -1 && coordinates_.second == -1) {
        return false;
    }
    return true;
}

ObjectType TruckCarItem::getTrafficObjectType() {
    return trafficObjectType_;
}

bool TruckCarItem::canBeRemoved() {
    return true;
}

IMovableItem* TruckCarItem::clone() {
    return new TruckCarItem(this->rect());
}

bool TruckCarItem::hasDiscretePosition() {
    return true;
}

MouseEventHandler* TruckCarItem::getMouseEventHandler() {
    return new TrafficParticipansMouseEventHandler();
}

