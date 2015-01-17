//Author: Bogdan Shkola
//Representing one cell/field of the street in the board street scene.

#ifndef BOARDCELL_H
#define BOARDCELL_H

#include <QGraphicsRectItem>
#include "../common/types.h"

class BoardCell : public QGraphicsRectItem
{
public:
    BoardCell(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void setChecked(bool checked); //sets the flag, changing the color of the cell
    bool isChecked();
    void setCoordinates(int x, int y); //sets coordinates metadata to the cell
    Coordinates getCoordinates();

signals:

public slots:

private:
    bool checked;
    Coordinates coordinates;
    Qt::GlobalColor checkedStreetColor;
    Qt::GlobalColor nonCheckedStreetColor;
};

#endif // BOARDCELL_H
