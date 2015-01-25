#include "../../view/items/cameraitem.h"

#include <QPainter>
#include "../mouseeventhandler/cameramouseeventhandler.h"

CameraItem::CameraItem(const QRectF& rect, QGraphicsItem* parent) :
    IMovableItem(rect, parent) {

    selectedColor_ = Qt::green;
    unselectedColor_ = Qt::darkGreen;

    color_ = unselectedColor_;
    coordinates_.first = -1;
    coordinates_.second = -1;
}

void CameraItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(QBrush(color_));
    painter->drawRect(this->rect());
}

void CameraItem::setCoordinates(int x, int y) {
    coordinates_.first = x;
    coordinates_.second = y;
}

Coordinates CameraItem::getCoordinates() {
    return coordinates_;
}

bool CameraItem::isOnBoard() {
    if (coordinates_.first == -1 && coordinates_.second == -1) {
        return false;
    }
    return true;
}

ObjectType CameraItem::getTrafficObjectType() {
    return trafficObjectType_;
}

bool CameraItem::canBeRemoved() {
    return true;
}

IMovableItem* CameraItem::clone() {
    return new CameraItem(this->rect());
}

bool CameraItem::hasDiscretePosition() {
    return false;
}

MouseEventHandler* CameraItem::getMouseEventHandler() {
    return CameraMouseEventHandler::getInstance();
}

void CameraItem::setSelected(bool isSelected) {
    if (isSelected) {
        color_ = selectedColor_;
    } else {
        color_ = unselectedColor_;
    }
    update();
}

int CameraItem::getId() {
    return id_;
}

void CameraItem::setId(int id) {
    id_ = id;
}
