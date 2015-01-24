#include "../../view/mouseeventhandler/cameramouseeventhandler.h"
#include "../../view/items/cameraitem.h"
#include "../../common/events/cameraaddedevent.h"
#include "../../common/events/camerareplacedevent.h"
#include "../../common/events/cameraremovedevent.h"
#include <iostream>

int CameraMouseEventHandler::indexCounter = 0;

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
    CameraItem* cameraItem = static_cast<CameraItem*>(item);

    if (!scene->isInsideBoard(event->scenePos())) {
        scene->removeItem(item);
        BlockingEventQueue::getInstance().push(new CameraRemovedEvent(cameraItem->getId()));
    } else {
        QPointF pressPosition = event->buttonDownScenePos(Qt::LeftButton);
        if (scene->isInsideBoard(pressPosition)) {
            BlockingEventQueue::getInstance().push(
                        new CameraReplacedEvent(cameraItem->getId(), Coordinates(event->scenePos().x() / scene->width(), event->scenePos().y() / scene->height())));
        } else {
            cameraItem->setId(indexCounter);
            BlockingEventQueue::getInstance().push(new CameraAddedEvent(indexCounter++, Coordinates(event->scenePos().x() / scene->width(), event->scenePos().y() / scene->height())));
        }
    }
}

