#include "../../view/items/cameraitem.h"

#include <QPainter>
#include "../mouseeventhandler/cameramouseeventhandler.h"

CameraItem::CameraItem(const QRectF& rect, QGraphicsItem* parent) :
    IMovableItem(rect, parent) {
    selectedColor_ = Qt::green;
    unselectedColor_ = Qt::darkGreen;
}

ObjectType CameraItem::getTrafficObjectType() {
    return trafficObjectType_;
}

IMovableItem* CameraItem::clone() {
    return new CameraItem(this->rect());
}

MouseEventHandler* CameraItem::getMouseEventHandler() {
    return CameraMouseEventHandler::getInstance();
}

int CameraItem::getId() {
    return id_;
}

void CameraItem::setId(int id) {
    id_ = id;
}
