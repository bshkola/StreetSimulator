//Author: Bogdan Shkola
//Implementation of DestinationMouseEventhandler class
#include "../../view/mouseeventhandler/destinationmouseeventhandler.h"
#include "../../view/items/destinationitem.h"
#include "../../view/items/itrafficparticipantitem.h"
#include "../../common/events/destinationreplaceevent.h"

DestinationMouseEventHandler::DestinationMouseEventHandler() {
}

void DestinationMouseEventHandler::handlePress(QGraphicsSceneMouseEvent*, BoardScene*, IMovableItem*) {

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
        ITrafficParticipantItem* parentItem = static_cast<ITrafficParticipantItem*>(item->parentItem());
        BlockingEventQueue::getInstance().push(
                    new DestinationReplaceEvent(parentItem->getId(), scene->getDiscreteCoordinates(event->scenePos())));
    } else {
        item->setPos(0, 0);
    }
}
