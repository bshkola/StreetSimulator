#ifndef CAMERAMOUSEEVENTHANDLER_H
#define CAMERAMOUSEEVENTHANDLER_H

#include "mouseeventhandler.h"

class CameraMouseEventHandler : public MouseEventHandler
{
    CameraMouseEventHandler();
public:

    void handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);

    static CameraMouseEventHandler* getInstance() {
        static CameraMouseEventHandler instance;
        return &instance;
    }
private:
    static int indexCounter;
};

#endif // CAMERAMOUSEEVENTHANDLER_H
