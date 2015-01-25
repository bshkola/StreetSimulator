//Author: Bogdan Shkola
//Implementation of DestinationItem class
#include "../../view/items/destinationitem.h"
#include "../mouseeventhandler/destinationmouseeventhandler.h"

DestinationItem::DestinationItem(const QRectF& rect, ITrafficParticipantItem* parent) :
    IMovableItem(rect, parent) {
    parentItem_ = parent;
    parentItem_->setDestination(this);
}

ObjectType DestinationItem::getTrafficObjectType() {
    return trafficObjectType_;
}

MouseEventHandler* DestinationItem::getMouseEventHandler() {
    return DestinationMouseEventHandler::getInstance();
}

IMovableItem* DestinationItem::clone() {
    return NULL;
}

bool DestinationItem::isSelected() {
    return (selected_ || parentItem()->isSelected());
}

void DestinationItem::setSelected(bool isSelected) {
    selected_ = isSelected;
    parentItem()->setSelected(isSelected);
    update();
}

ITrafficParticipantItem* DestinationItem::parentItem() {
    return parentItem_;
}

void DestinationItem::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->setBrush(QBrush(Qt::black));
    painter->drawRect(this->rect());
}
