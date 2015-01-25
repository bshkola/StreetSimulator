//Author: Bogdan Shkola
//Interface for scene items
#ifndef IMOVABLEITEM_H
#define IMOVABLEITEM_H

#include <QGraphicsRectItem>
#include <QPainter>
#include "../mouseeventhandler/mouseeventhandler.h"
#include "../../common/types.h"

class MouseEventHandler;

class IMovableItem : public QGraphicsRectItem
{
public:
    IMovableItem(const QRectF& rect, QGraphicsItem* parent = 0);
    //Painting the item with selected color
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    //Gets type of the item object
    virtual ObjectType getTrafficObjectType() = 0;
    //Gets proper mouse event handler
    virtual MouseEventHandler* getMouseEventHandler() = 0;
    //Clones the object
    virtual IMovableItem* clone() = 0;
    //Sets selected flag of the item
    virtual void setSelected(bool isSelected);
    //Checks selected flag of the item
    virtual bool isSelected();

protected:
    //Selected flag of the item
    bool selected_;
    //color of selected item
    Qt::GlobalColor selectedColor_;
    //color of unselected item
    Qt::GlobalColor unselectedColor_;
};

#endif // IMOVABLEITEM_H
