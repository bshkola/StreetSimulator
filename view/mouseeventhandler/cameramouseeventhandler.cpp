#include "../../view/mouseeventhandler/cameramouseeventhandler.h"
#include <iostream>

CameraMouseEventHandler::CameraMouseEventHandler()
{
}

void CameraMouseEventHandler::handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) {

}

void CameraMouseEventHandler::handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) {
    if (scene->isInsideScene(event->scenePos())) {
        item->setPos(event->scenePos() - item->boundingRect().center());
    }
}

void CameraMouseEventHandler::handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) {
    if (!scene->isInsideBoard(event->scenePos())) {
        scene->removeItem(item);
        std::cout << "item removed" << std::endl;
    }
}

