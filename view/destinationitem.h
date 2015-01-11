#ifndef DESTINATIONITEM_H
#define DESTINATIONITEM_H

#include "../common/coordinates.h"
#include "imovableitem.h"

namespace Ui {

    class DestinationItem : public IMovableItem
    {
    public:
        DestinationItem(IMovableItem* parentItem_, const QRectF& rect, QGraphicsItem* parent = 0);

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        //void setCoordinates(int x, int y); //sets coordinates metadata to the cell
        bool isOnBoard();
        int getItemIndex();
        bool canBeRemoved();
        IMovableItem* clone();
        bool hasDiscretePosition();


    private:
        Coordinates coordinates_;
        Qt::GlobalColor color_;

        IMovableItem* parentItem;

        const static int item_index_ = -1;
    };

}

#endif // DESTINATIONITEM_H
