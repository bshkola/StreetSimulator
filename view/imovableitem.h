#ifndef IMOVABLEITEM_H
#define IMOVABLEITEM_H

#include <QGraphicsRectItem>
#include <iostream>

class IMovableItem : public QGraphicsRectItem
{
public:
    IMovableItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);

    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) = 0;
    virtual void setCoordinates(int x, int y) = 0; //sets coordinates metadata to the cell
    virtual bool isOnBoard() = 0;
    virtual int getItemIndex() = 0;

};

#endif // IMOVABLEITEM_H
