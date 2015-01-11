#include "../../view/mouseeventhandler/destinationmouseeventhandler.h"
#include "../items/destinationitem.h"

DestinationMouseEventHandler::DestinationMouseEventHandler()
{
}

void DestinationMouseEventHandler::handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) {

}

void DestinationMouseEventHandler::handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) {
    if (scene->isInsideScene(event->scenePos())) {
        item->setPos(event->scenePos() - item->boundingRect().center() - ((DestinationItem*)item)->parentItem()->pos());
    }
}

void DestinationMouseEventHandler::handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) {
    if (scene->isInsideBoard(event->scenePos())) {
        QPointF position = scene->getDiscretePosition(event->scenePos());
        item->setPos(position  - ((DestinationItem*)item)->parentItem()->pos());
    } else {
        item->setPos(0, 0);
    }
}
