#include "../view/truckcarcell.h"

#include <QPainter>

namespace Ui {
    TruckCarCell::TruckCarCell(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent) :
        QGraphicsRectItem(x + width / 4, y + height / 4, width / 2, height / 2, parent) {
        color = Qt::blue;
    }

    void TruckCarCell::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
        painter->setBrush(QBrush(color));
        painter->drawRect(this->rect());
    }

    void TruckCarCell::setCoordinates(int x, int y) {
        coordinates.x = x;
        coordinates.y = y;
    }

    Coordinates TruckCarCell::getCoordinates() {
        return coordinates;
    }
}
