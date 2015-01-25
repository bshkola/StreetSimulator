//Author: Bogdan Shkola
//Handler for mouse pressing events on the camera items
#ifndef CAMERAMOUSEEVENTHANDLER_H
#define CAMERAMOUSEEVENTHANDLER_H

#include "mouseeventhandler.h"

class CameraMouseEventHandler : public MouseEventHandler
{
    CameraMouseEventHandler();
public:
    //Handles mouse pressing on the items
    void handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);
    void handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item);

    //Singleton
    static CameraMouseEventHandler* getInstance() {
        static CameraMouseEventHandler instance;
        return &instance;
    }
private:
    //Counter of the index for camera items
    static int indexCounter;
};

#endif // CAMERAMOUSEEVENTHANDLER_H
