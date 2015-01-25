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
    //Paints the cell
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    //Sets the flag, changing the color of the cell
    void setChecked(bool checked_);
    //Checks the flag, changing the color of the cell
    bool isChecked();
    //Sets coordinates metadata to the cell
    void setCoordinates(int x, int y);
    //Gets coordinates metadata of the cell
    Position getCoordinates();

private:
    //Checked flag
    bool checked_;
    //Coordinates flag
    Position coordinates_;
    //Color of the checked cell
    Qt::GlobalColor checkedStreetColor_;
    //Color of the unchecked cell
    Qt::GlobalColor unheckedStreetColor_;
};

#endif // BOARDCELL_H
