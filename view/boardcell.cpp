#include "boardcell.h"
#include <QPainter>
#include <QGraphicsRectItem>

namespace Ui {
    BoardCell::BoardCell(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent) :
        QGraphicsRectItem(x, y, width, height, parent) {
        checked = false;
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
            color = Qt::red;
        } else {
            color = Qt::white;
        }
        painter->setBrush(QBrush(color));
        painter->drawRect(this->rect());
    }
}
