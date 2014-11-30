#ifndef BOARDCELL_H
#define BOARDCELL_H

#include <QGraphicsRectItem>

class BoardCell : public QGraphicsRectItem
{
public:
    BoardCell(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = 0);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void setChecked(bool checked);
    bool isChecked();
signals:

public slots:

private:
    bool checked;
};

#endif // BOARDCELL_H
