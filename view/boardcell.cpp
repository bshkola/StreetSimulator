//Author: Bogdan Shkola
//Implementation of BoardCell class
#include "boardcell.h"
#include <QPainter>
#include <QGraphicsRectItem>

BoardCell::BoardCell(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent) :
    QGraphicsRectItem(x, y, width, height, parent) {
    checked_ = false;
    checkedStreetColor_ = Qt::gray;
    unheckedStreetColor_ = Qt::white;
}

void BoardCell::setChecked(bool checked) {
    this->checked_ = checked;
}

bool BoardCell::isChecked() {
    return this->checked_;
}

void BoardCell::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Qt::GlobalColor color;
    if (checked_) {
        color = checkedStreetColor_;
    } else {
        color = unheckedStreetColor_;
    }
    painter->setBrush(QBrush(color));
    painter->drawRect(this->rect());
}

void BoardCell::setCoordinates(int x, int y) {
    coordinates_.first = x;
    coordinates_.second = y;
}

Position BoardCell::getCoordinates() {
    return coordinates_;
}
