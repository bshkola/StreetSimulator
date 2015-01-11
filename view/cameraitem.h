#ifndef CAMERAITEM_H
#define CAMERAITEM_H

#include "../common/coordinates.h"
#include "imovableitem.h"

namespace Ui {
    class CameraItem : public IMovableItem
    {
    public:
        CameraItem(const QRectF& rect, QGraphicsItem* parent = 0);

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        void setCoordinates(int x, int y); //sets coordinates metadata to the cell
        Coordinates getCoordinates();
        bool isOnBoard();
        int getItemIndex();
        bool canBeRemoved();
        IMovableItem* clone();
        bool hasDiscretePosition();

    private:
        Coordinates coordinates_;
        Qt::GlobalColor color_;

        const static int item_index_ = 3;
    };

}

#endif // CAMERAITEM_H
