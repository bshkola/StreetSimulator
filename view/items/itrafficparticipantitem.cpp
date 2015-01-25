#include "../../view/items/itrafficparticipantitem.h"

ITrafficParticipantItem::ITrafficParticipantItem(const QRectF& rect, QGraphicsItem* parent) :
    IMovableItem(rect, parent)
{
    destinationItem_ = NULL;
}

void ITrafficParticipantItem::setDestination(DestinationItem* destinationItem) {
    destinationItem_ = destinationItem;
}

void ITrafficParticipantItem::setSelected(bool isSelected) {
    IMovableItem::setSelected(isSelected);
//    if (isSelected || destinationItem_->isSelected()) {
//        destinationItem_->setVisible(true);
//    } else {
//        destinationItem_->setVisible(false);
//    }
    destinationItem_->setVisible(isSelected);
    update();
}

void ITrafficParticipantItem::resetDestinationPosition() {
    destinationItem_->setPos(0, 0);
}

int ITrafficParticipantItem::getId() {
    return id_;
}

void ITrafficParticipantItem::setId(int id) {
    id_ = id;
}
