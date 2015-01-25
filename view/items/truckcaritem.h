#ifndef TRUCKCARITEM_H
#define TRUCKCARITEM_H

#include "itrafficparticipantitem.h"

class TruckCarItem : public ITrafficParticipantItem
{
public:
    TruckCarItem(const QRectF& rect, QGraphicsItem* parent = 0);

    ObjectType getTrafficObjectType();
    IMovableItem* clone();
    MouseEventHandler* getMouseEventHandler();

private:
    const static ObjectType trafficObjectType_ = TRUCK;
};

#endif // TRUCKCARITEM_H
