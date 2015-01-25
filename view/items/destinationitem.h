//Author: Bogdan Shkola
//Scene item representing destination of the traffic item
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
    //Inherited methods
    ObjectType getTrafficObjectType();
    IMovableItem* clone();
    MouseEventHandler* getMouseEventHandler();
    bool isSelected();
    void setSelected(bool isSelected);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

    //Gets the item which destination it is
    ITrafficParticipantItem* parentItem();
private:
    //Item to which destination is linked
    ITrafficParticipantItem* parentItem_;
    const static ObjectType trafficObjectType_ = DESTINATION;
};

#endif // DESTINATIONITEM_H
