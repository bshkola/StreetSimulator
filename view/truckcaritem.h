#ifndef TRUCKCARITEM_H
#define TRUCKCARITEM_H

#include "../common/coordinates.h"
#include "imovableitem.h"

namespace Ui {

    class TruckCarItem : public IMovableItem
    {
    public:
        TruckCarItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        void setCoordinates(int x, int y); //sets coordinates metadata to the cell
        Coordinates getCoordinates();
        bool isOnBoard();

    private:
        Coordinates coordinates;
        Qt::GlobalColor color;
    };

}
#endif // TRUCKCARCELL_H
