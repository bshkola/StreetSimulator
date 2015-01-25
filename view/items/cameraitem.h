//Author: Bogdan Shkola
//Scene item representing camera
#ifndef CAMERAITEM_H
#define CAMERAITEM_H

#include "../../common/types.h"
#include "imovableitem.h"

class CameraItem : public IMovableItem
{
public:
    CameraItem(const QRectF& rect, QGraphicsItem* parent = 0);
    //Inherited methods
    ObjectType getTrafficObjectType();
    IMovableItem* clone();
    MouseEventHandler* getMouseEventHandler();

    //Gets id of the camera
    int getId();
    //Sets id for the camera
    void setId(int id);

private:
    //Id of the camera
    int id_;
    const static ObjectType trafficObjectType_ = CAMERA;
};

#endif // CAMERAITEM_H
