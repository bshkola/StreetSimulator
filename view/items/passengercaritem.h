#ifndef PASSENGERCARITEM_H
#define PASSENGERCARITEM_H

#include "../../common/coordinates.h"
#include "itrafficparticipantitem.h"

class PassengerCarItem : public ITrafficParticipantItem
{
public:
    //PassangerCarItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);
    PassengerCarItem(const QRectF& rect, QGraphicsItem* parent = 0);

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

    const static int item_index_ = 1;
};

#endif // PASSENGERCARITEM_H
