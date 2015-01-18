#include "../../view/mouseeventhandler/cameramouseeventhandler.h"
#include "../../common/events/cameraaddedevent.h"
#include "../../common/events/camerareplacedevent.h"
#include "../../common/events/cameraremovedevent.h"
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
        QPointF pressPosition = event->buttonDownScenePos(Qt::LeftButton);
        BlockingEventQueue::getInstance().push(new CameraRemovedEvent(Coordinates(pressPosition.x() / scene->width(), pressPosition.y() / scene->height())));
    } else {
        QPointF pressPosition = event->buttonDownScenePos(Qt::LeftButton);
        if (scene->isInsideBoard(pressPosition)) {
            BlockingEventQueue::getInstance().push(new CameraReplacedEvent(Coordinates(pressPosition.x() / scene->width(), pressPosition.y() / scene->height()),
                                                                           Coordinates(event->scenePos().x() / scene->width(), event->scenePos().y() / scene->height())));
        } else {
            BlockingEventQueue::getInstance().push(new CameraAddedEvent(Coordinates(event->scenePos().x() / scene->width(), event->scenePos().y() / scene->height())));
        }
    }
}

