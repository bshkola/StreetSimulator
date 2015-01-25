//Author: Bogdan Shkola
//interface representing traffic object
#ifndef ITRAFFICPARTICIPANTITEM_H
#define ITRAFFICPARTICIPANTITEM_H

#include "imovableitem.h"
#include "destinationitem.h"
#include "../../common/types.h"
#include <QPainter>

class DestinationItem;

class ITrafficParticipantItem : public QObject, public IMovableItem
{
    //Properties for animation
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    ITrafficParticipantItem(const QRectF& rect, QGraphicsItem* parent = 0);
    //Inherited methods
    ObjectType getTrafficObjectType() = 0;
    MouseEventHandler* getMouseEventHandler() = 0;
    IMovableItem* clone() = 0;
    void setSelected(bool isSelected);

    //Sets destination item for the traffic object
    void setDestination(DestinationItem* destinationItem);
    //Resets destination's position to traffic item's position
    void resetDestinationPosition();
    //Gets id of the traffic item
    int getId();
    //Sets id of the traffic item
    void setId(int id);

protected:
    //Id of the traffic item
    int id_;

private:
    DestinationItem* destinationItem_;
};

#endif // ITRAFFICPARTICIPANTITEM_H
