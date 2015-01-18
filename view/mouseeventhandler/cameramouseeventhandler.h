#ifndef CAMERAMOUSEEVENTHANDLER_H
#define CAMERAMOUSEEVENTHANDLER_H

#include "mouseeventhandler.h"

class CameraMouseEventHandler : public MouseEventHandler
{
public:
    CameraMouseEventHandler();

    void handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
};

#endif // CAMERAMOUSEEVENTHANDLER_H
