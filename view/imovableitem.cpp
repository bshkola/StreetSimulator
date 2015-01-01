#include "../view/imovableitem.h"

IMovableItem::IMovableItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent) :
    QGraphicsRectItem(x, y, width, height, parent)
{
}
