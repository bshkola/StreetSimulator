#include "../view/destinationitem.h"

#include <QPainter>

namespace Ui {

    DestinationItem::DestinationItem(IMovableItem* parentItem_,const QRectF& rect, QGraphicsItem* parent) :
        IMovableItem(rect, parent) {
        color_ = Qt::black;
        coordinates_.x = -1;
        coordinates_.y = -1;
        parentItem = parentItem_;
        //parentItem->setDestination(this);
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
        return NULL;//new DestinationItem(this->rect());
    }

    bool DestinationItem::hasDiscretePosition() {
        return true;
    }

}
