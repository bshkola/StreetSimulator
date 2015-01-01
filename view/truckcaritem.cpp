#include "../view/truckcaritem.h"

#include <QPainter>

namespace Ui {
    TruckCarItem::TruckCarItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent) :
        IMovableItem(x + width / 4, y + height / 4, width / 2, height / 2, parent) {
        color = Qt::blue;
        coordinates.x = -1;
        coordinates.y = -1;
    }

    void TruckCarItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
        painter->setBrush(QBrush(color));
        painter->drawRect(this->rect());
    }

    void TruckCarItem::setCoordinates(int x, int y) {
        coordinates.x = x;
        coordinates.y = y;
    }

    Coordinates TruckCarItem::getCoordinates() {
        return coordinates;
    }

    using namespace std;
    bool TruckCarItem::isOnBoard() {
        if (coordinates.x == -1 && coordinates.y == -1) {
            return false;
        }
        return true;
    }

}
