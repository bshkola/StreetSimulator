#ifndef PEDESTRIANITEM_H
#define PEDESTRIANITEM_H

#include "itrafficparticipantitem.h"

class PedestrianItem : public ITrafficParticipantItem
{
public:
    PedestrianItem(const QRectF& rect, QGraphicsItem* parent = 0);

    ObjectType getTrafficObjectType();
    MouseEventHandler* getMouseEventHandler();
    IMovableItem* clone();

private:
    const static ObjectType trafficObjectType_ = PEDESTRIAN;
};

#endif // PEDESTRIANITEM_H
