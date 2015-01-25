#ifndef CAMERAITEM_H
#define CAMERAITEM_H

#include "../../common/types.h"
#include "imovableitem.h"

class CameraItem : public IMovableItem
{
public:
    CameraItem(const QRectF& rect, QGraphicsItem* parent = 0);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void setCoordinates(int x, int y); //sets coordinates metadata to the cell
    Coordinates getCoordinates();
    bool isOnBoard();
    ObjectType getTrafficObjectType();
    bool canBeRemoved();
    IMovableItem* clone();
    bool hasDiscretePosition();
    MouseEventHandler* getMouseEventHandler();
    void setSelected(bool isSelected);

    int getId();
    void setId(int id);

private:
    int id_;
    Coordinates coordinates_;
    Qt::GlobalColor color_;

    Qt::GlobalColor selectedColor_;
    Qt::GlobalColor unselectedColor_;

    const static ObjectType trafficObjectType_ = CAMERA;
};

#endif // CAMERAITEM_H
