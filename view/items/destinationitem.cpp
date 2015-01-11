#include "../../view/items/destinationitem.h"
#include "../mouseeventhandler/destinationmouseeventhandler.h"
#include "itrafficparticipantitem.h"

#include <QPainter>

DestinationItem::DestinationItem(const QRectF& rect, ITrafficParticipantItem* parent) :
    IMovableItem(rect, parent) {
    color_ = Qt::black;
    coordinates_.x = -1;
    coordinates_.y = -1;
    selected_ = false;

    parentItem_ = parent;
    parentItem_->setDestination(this);
}

void DestinationItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setBrush(QBrush(color_));
    painter->drawRect(this->rect());
}

//    void DestinationItem::setCoordinates(int x, int y) {
//        coordinates_.x = x;
//        coordinates_.y = y;
//    }

//    Coordinates DestinationItem::getCoordinates() {
//        return coordinates_;
//    }

bool DestinationItem::isOnBoard() {
    if (coordinates_.x == -1 && coordinates_.y == -1) {
        return false;
    }
    return true;
}

int DestinationItem::getItemIndex() {
    return item_index_;
}

bool DestinationItem::canBeRemoved() {
    return false;
}

IMovableItem* DestinationItem::clone() {
    return NULL;
}

bool DestinationItem::hasDiscretePosition() {
    return true;
}

MouseEventHandler* DestinationItem::getMouseEventHandler() {
    return new DestinationMouseEventHandler();
}

void DestinationItem::setSelected(bool selected) {
    selected_ = selected;
    parentItem_->setSelected(selected);
}

bool DestinationItem::isSelected() {
    return selected_;
}


ITrafficParticipantItem* DestinationItem::parentItem() {
    return parentItem_;
}
