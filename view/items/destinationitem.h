#ifndef DESTINATIONITEM_H
#define DESTINATIONITEM_H

#include "../../common/types.h"
#include "imovableitem.h"
#include "itrafficparticipantitem.h"

class ITrafficParticipantItem;

class DestinationItem : public IMovableItem
{
public:
    DestinationItem(const QRectF& rect, ITrafficParticipantItem* parent = 0);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    //void setCoordinates(int x, int y); //sets coordinates metadata to the cell
    bool isOnBoard();
    ObjectType getTrafficObjectType();
    bool canBeRemoved();
    IMovableItem* clone();
    bool hasDiscretePosition();
    MouseEventHandler* getMouseEventHandler();
    void setSelected(bool isSelected);
    bool isSelected();

    ITrafficParticipantItem* parentItem();

private:
    Coordinates coordinates_;
    Qt::GlobalColor color_;
    ITrafficParticipantItem* parentItem_;

    bool selected_;
    const static ObjectType trafficObjectType_ = DESTINATION;
};

#endif // DESTINATIONITEM_H
