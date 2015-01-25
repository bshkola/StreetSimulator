#include "../../view/items/imovableitem.h"

IMovableItem::IMovableItem(const QRectF& rect, QGraphicsItem* parent) :
    QGraphicsRectItem(rect, parent), selected_(false)
{
}

void IMovableItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    if (selected_) {
        painter->setBrush(QBrush(selectedColor_));
    } else {
        painter->setBrush(QBrush(unselectedColor_));
    }
    painter->drawRect(this->rect());
}

void IMovableItem::setSelected(bool isSelected) {
    selected_ = isSelected;
    update();
}

bool IMovableItem::isSelected() {
    return selected_;
}
