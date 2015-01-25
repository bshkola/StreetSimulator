#ifndef CAMERAITEM_H
#define CAMERAITEM_H

#include "../../common/types.h"
#include "imovableitem.h"

class CameraItem : public IMovableItem
{
public:
    CameraItem(const QRectF& rect, QGraphicsItem* parent = 0);

    ObjectType getTrafficObjectType();
    IMovableItem* clone();
    MouseEventHandler* getMouseEventHandler();

    int getId();
    void setId(int id);

private:
    int id_;

    const static ObjectType trafficObjectType_ = CAMERA;
};

#endif // CAMERAITEM_H
