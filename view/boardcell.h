#ifndef BOARDCELL_H
#define BOARDCELL_H

#include <QGraphicsRectItem>
#include "../common/coordinates.h"

namespace Ui {
    class BoardCell : public QGraphicsRectItem
    {
    public:
        BoardCell(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        void setChecked(bool checked);
        bool isChecked();
        void setCoordinates(int x, int y);
        Coordinates getCoordinates();

    signals:

    public slots:

    private:
        bool checked;
        Coordinates coordinates;
        Qt::GlobalColor checkedStreetColor;
        Qt::GlobalColor nonCheckedStreetColor;

    };
}

#endif // BOARDCELL_H
