#ifndef TRUCKCARITEM_H
#define TRUCKCARITEM_H

#include "../common/coordinates.h"
#include "imovableitem.h"

namespace Ui {

    class TruckCarItem : public IMovableItem
    {
    public:
        //TruckCarItem(int itemIndex, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);
        TruckCarItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        void setCoordinates(int x, int y); //sets coordinates metadata to the cell
        Coordinates getCoordinates();
        bool isOnBoard();
        int getItemIndex();

    private:
        Coordinates coordinates_;
        Qt::GlobalColor color_;

        const static int item_index_ = 0;
    };

}
#endif // TRUCKCARCELL_H
