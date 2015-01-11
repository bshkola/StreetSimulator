#include "../view/truckcaritem.h"

#include <QPainter>

namespace Ui {
    /*TruckCarItem::TruckCarItem(int itemIndex, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent) :
        IMovableItem(x + width / 4, y + height / 4, width / 2, height / 2, parent) {
        color_ = Qt::blue;
        coordinates_.x = -1;
        coordinates_.y = -1;
        item_index_ = itemIndex;
    }*/

    TruckCarItem::TruckCarItem(const QRectF& rect, QGraphicsItem* parent) :
        IMovableItem(rect, parent) {
        color_ = Qt::blue;
        coordinates_.x = -1;
        coordinates_.y = -1;
    }

    void TruckCarItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
        painter->setBrush(QBrush(color_));
        painter->drawRect(this->rect());
    }

    void TruckCarItem::setCoordinates(int x, int y) {
        coordinates_.x = x;
        coordinates_.y = y;
    }

    Coordinates TruckCarItem::getCoordinates() {
        return coordinates_;
    }

    bool TruckCarItem::isOnBoard() {
        if (coordinates_.x == -1 && coordinates_.y == -1) {
            return false;
        }
        return true;
    }

    int TruckCarItem::getItemIndex() {
        return item_index_;
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


}
