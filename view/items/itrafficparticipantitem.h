#ifndef ITRAFFICPARTICIPANTITEM_H
#define ITRAFFICPARTICIPANTITEM_H

#include "imovableitem.h"
#include "destinationitem.h"
#include "../../common/types.h"
#include <QPainter>

class DestinationItem;

class ITrafficParticipantItem : public QObject, public IMovableItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    ITrafficParticipantItem(const QRectF& rect, QGraphicsItem* parent = 0);
    ObjectType getTrafficObjectType() = 0;
    MouseEventHandler* getMouseEventHandler() = 0;
    IMovableItem* clone() = 0;
    void setSelected(bool isSelected);

    void setDestination(DestinationItem* destinationItem);
    void resetDestinationPosition();
    int getId();
    void setId(int id);

protected:
    int id_;

private:
    DestinationItem* destinationItem_;
};

#endif // ITRAFFICPARTICIPANTITEM_H
