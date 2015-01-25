#include "../../view/items/pedestrianitem.h"
#include "../mouseeventhandler/trafficparticipansmouseeventhandler.h"
#include "itrafficparticipantitem.h"
#include <QPainter>

PedestrianItem::PedestrianItem(const QRectF& rect, QGraphicsItem* parent) :
    ITrafficParticipantItem(rect, parent) {

    selectedColor_ = Qt::yellow;
    unselectedColor_ = Qt::darkYellow;
    color_ = unselectedColor_;

    coordinates_.first = -1;
    coordinates_.second = -1;
}

void PedestrianItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(QBrush(color_));
    painter->drawRect(this->rect());
}

void PedestrianItem::setCoordinates(int x, int y) {
    coordinates_.first = x;
    coordinates_.second = y;
}

Coordinates PedestrianItem::getCoordinates() {
    return coordinates_;
}

bool PedestrianItem::isOnBoard() {
    if (coordinates_.first == -1 && coordinates_.second == -1) {
        return false;
    }
    return true;
}

ObjectType PedestrianItem::getTrafficObjectType() {
    return trafficObjectType_;
}

bool PedestrianItem::canBeRemoved() {
    return true;
}

IMovableItem* PedestrianItem::clone() {
    return new PedestrianItem(this->rect());
}

bool PedestrianItem::hasDiscretePosition() {
    return true;
}

MouseEventHandler* PedestrianItem::getMouseEventHandler() {
    return TrafficParticipansMouseEventHandler::getInstance();
}

