#ifndef PEDESTRIANITEM_H
#define PEDESTRIANITEM_H

#include "../../common/types.h"
#include "itrafficparticipantitem.h"

class PedestrianItem : public ITrafficParticipantItem
{
public:
    PedestrianItem(const QRectF& rect, QGraphicsItem* parent = 0);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void setCoordinates(int x, int y); //sets coordinates metadata to the cell
    Coordinates getCoordinates();
    bool isOnBoard();
    ObjectType getTrafficObjectType();
    bool canBeRemoved();
    IMovableItem* clone();
    bool hasDiscretePosition();
    MouseEventHandler* getMouseEventHandler();

private:
    Coordinates coordinates_;

    const static ObjectType trafficObjectType_ = PEDESTRIAN;
};

#endif // PEDESTRIANITEM_H
