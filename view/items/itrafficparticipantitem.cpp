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
    if (isSelected || destinationItem_->isSelected()) {
        color_ = selectedColor_;
        destinationItem_->setVisible(true);
    } else {
        color_ = unselectedColor_;
        destinationItem_->setVisible(false);
    }
    update();
}

void ITrafficParticipantItem::resetDestinationPosition() {
    destinationItem_->setPos(0, 0);
}
