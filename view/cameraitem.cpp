#include "../view/cameraitem.h"

#include <QPainter>

namespace Ui {

    CameraItem::CameraItem(const QRectF& rect, QGraphicsItem* parent) :
        IMovableItem(rect, parent) {
        color_ = Qt::green;
        coordinates_.x = -1;
        coordinates_.y = -1;
    }

    void CameraItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
        painter->setBrush(QBrush(color_));
        painter->drawRect(this->rect());
    }

    void CameraItem::setCoordinates(int x, int y) {
        coordinates_.x = x;
        coordinates_.y = y;
    }

    Coordinates CameraItem::getCoordinates() {
        return coordinates_;
    }

    bool CameraItem::isOnBoard() {
        if (coordinates_.x == -1 && coordinates_.y == -1) {
            return false;
        }
        return true;
    }

    int CameraItem::getItemIndex() {
        return item_index_;
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


}
