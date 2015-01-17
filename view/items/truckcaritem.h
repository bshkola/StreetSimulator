#ifndef TRUCKCARITEM_H
#define TRUCKCARITEM_H

#include "../../common/types.h"
#include "itrafficparticipantitem.h"

class TruckCarItem : public ITrafficParticipantItem
{
public:
    //TruckCarItem(int itemIndex, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);
    TruckCarItem(const QRectF& rect, QGraphicsItem* parent = 0);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void setCoordinates(int x, int y); //sets coordinates metadata to the cell
    Coordinates getCoordinates();
    bool isOnBoard();
    int getItemIndex();
    bool canBeRemoved();
    IMovableItem* clone();
    bool hasDiscretePosition();
    MouseEventHandler* getMouseEventHandler();

private:
    Coordinates coordinates_;

    const static int item_index_ = 0;
};

#endif // TRUCKCARITEM_H
