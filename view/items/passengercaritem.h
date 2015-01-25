//Author: Bogdan Shkola
//Scene item representing passenger car
#ifndef PASSENGERCARITEM_H
#define PASSENGERCARITEM_H

#include "itrafficparticipantitem.h"

class PassengerCarItem : public ITrafficParticipantItem
{
public:
    PassengerCarItem(const QRectF& rect, QGraphicsItem* parent = 0);
    //Inherited methods
    ObjectType getTrafficObjectType();
    IMovableItem* clone();
    MouseEventHandler* getMouseEventHandler();

private:
    const static ObjectType trafficObjectType_ = CAR;
};

#endif // PASSENGERCARITEM_H
