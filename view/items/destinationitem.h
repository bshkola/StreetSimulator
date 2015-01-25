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
    ObjectType getTrafficObjectType();
    IMovableItem* clone();
    MouseEventHandler* getMouseEventHandler();
    bool isSelected();
    void setSelected(bool isSelected);

    ITrafficParticipantItem* parentItem();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
private:
    ITrafficParticipantItem* parentItem_;
    const static ObjectType trafficObjectType_ = DESTINATION;
};

#endif // DESTINATIONITEM_H
