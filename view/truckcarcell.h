#ifndef TRUCKCARCELL_H
#define TRUCKCARCELL_H

#include <QGraphicsRectItem>
#include "../common/coordinates.h"

namespace Ui {

    class TruckCarCell : public QGraphicsRectItem
    {
    public:
        TruckCarCell(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        void setCoordinates(int x, int y); //sets coordinates metadata to the cell
        Coordinates getCoordinates();

    private:
        Coordinates coordinates;
        Qt::GlobalColor color;
    };

}
#endif // TRUCKCARCELL_H
