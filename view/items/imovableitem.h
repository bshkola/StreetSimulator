#ifndef IMOVABLEITEM_H
#define IMOVABLEITEM_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <iostream>
#include "../mouseeventhandler/mouseeventhandler.h"
#include "../../common/types.h"

class MouseEventHandler;

class IMovableItem : public QGraphicsRectItem
{
public:
    IMovableItem(const QRectF& rect, QGraphicsItem* parent = 0);

    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    virtual ObjectType getTrafficObjectType() = 0;
    virtual MouseEventHandler* getMouseEventHandler() = 0;
    virtual IMovableItem* clone() = 0;
    virtual void setSelected(bool isSelected);
    virtual bool isSelected();


protected:
    bool selected_;

    Qt::GlobalColor selectedColor_;
    Qt::GlobalColor unselectedColor_;
};

#endif // IMOVABLEITEM_H
