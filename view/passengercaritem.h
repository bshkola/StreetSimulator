#ifndef PASSENGERCARITEM_H
#define PASSENGERCARITEM_H

#include "../common/coordinates.h"
#include "imovableitem.h"

namespace Ui {

    class PassengerCarItem : public IMovableItem
    {
    public:
        //PassangerCarItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);
        PassengerCarItem(const QRectF& rect, QGraphicsItem* parent = 0);

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        void setCoordinates(int x, int y); //sets coordinates metadata to the cell
        Coordinates getCoordinates();
        bool isOnBoard();
        int getItemIndex();
        IMovableItem* clone();

    private:
        Coordinates coordinates_;
        Qt::GlobalColor color_;

        const static int item_index_ = 1;
    };

}

#endif // PASSENGERCARITEM_H
