#include "boardcell.h"
#include <QPainter>
#include <QGraphicsRectItem>

namespace Ui {
    BoardCell::BoardCell(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent) :
        QGraphicsRectItem(x, y, width, height, parent) {
        checked = false;
        checkedStreetColor = Qt::gray;
        nonCheckedStreetColor = Qt::white;
    }

    void BoardCell::setChecked(bool checked) {
        this->checked = checked;
    }

    bool BoardCell::isChecked() {
        return this->checked;
    }

    void BoardCell::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
        Qt::GlobalColor color;
        if (checked) {
            color = checkedStreetColor;
        } else {
            color = nonCheckedStreetColor;
        }
        painter->setBrush(QBrush(color));
        painter->drawRect(this->rect());
    }

    void BoardCell::setCoordinates(int x, int y) {
        coordinates.x = x;
        coordinates.y = y;
    }

    Coordinates BoardCell::getCoordinates() {
        return coordinates;
    }

}
