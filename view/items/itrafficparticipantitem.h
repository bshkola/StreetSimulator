#ifndef ITRAFFICPARTICIPANTITEM_H
#define ITRAFFICPARTICIPANTITEM_H

#include "imovableitem.h"
#include "destinationitem.h"

class DestinationItem;

class ITrafficParticipantItem : public IMovableItem
{
public:
    ITrafficParticipantItem(const QRectF& rect, QGraphicsItem* parent = 0);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) = 0;
    //virtual void setCoordinates(int x, int y) = 0; //sets coordinates metadata to the cell
    bool isOnBoard() = 0;
    ObjectType getTrafficObjectType() = 0;
    bool canBeRemoved() = 0;
    bool hasDiscretePosition() = 0;
    MouseEventHandler* getMouseEventHandler() = 0;

    void setSelected(bool isSelected);
    void setDestination(DestinationItem* destinationItem);
    void resetDestinationPosition();

    IMovableItem* clone() = 0;

protected:
    Qt::GlobalColor color_;

    Qt::GlobalColor selectedColor_;
    Qt::GlobalColor unselectedColor_;

private:
    DestinationItem* destinationItem_;
};

#endif // ITRAFFICPARTICIPANTITEM_H
