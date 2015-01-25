//Author: Bogdan Shkola
//Interface for trafic scene items
#ifndef TRUCKCARITEM_H
#define TRUCKCARITEM_H

#include "itrafficparticipantitem.h"

class TruckCarItem : public ITrafficParticipantItem
{
public:
    TruckCarItem(const QRectF& rect, QGraphicsItem* parent = 0);

    //Inherited methods
    ObjectType getTrafficObjectType();
    IMovableItem* clone();
    MouseEventHandler* getMouseEventHandler();

private:
    const static ObjectType trafficObjectType_ = TRUCK;
};

#endif // TRUCKCARITEM_H
