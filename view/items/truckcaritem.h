#ifndef TRUCKCARITEM_H
#define TRUCKCARITEM_H

#include "../../common/types.h"
#include "itrafficparticipantitem.h"

class TruckCarItem : /*public QObject, */public ITrafficParticipantItem
{
//    Q_OBJECT
//    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    //TruckCarItem(int itemIndex, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);
    TruckCarItem(const QRectF& rect, QGraphicsItem* parent = 0);

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

    const static ObjectType trafficObjectType_ = TRUCK;
};

#endif // TRUCKCARITEM_H
