#include "../../view/mouseeventhandler/trafficparticipansmouseeventhandler.h"
#include "../items/destinationitem.h"
#include "../items/itrafficparticipantitem.h"

TrafficParticipansMouseEventHandler::TrafficParticipansMouseEventHandler()
{
}

void TrafficParticipansMouseEventHandler::handlePress(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) {

}

void TrafficParticipansMouseEventHandler::handleMove(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) {
    if (scene->isInsideScene(event->scenePos())) {
        item->setPos(event->scenePos() - item->boundingRect().center());
    }
}

void TrafficParticipansMouseEventHandler::handleRelease(QGraphicsSceneMouseEvent* event, BoardScene* scene, IMovableItem* item) {
    if (scene->isInsideBoard(event->scenePos())) {
        QPointF position = scene->getDiscretePosition(event->scenePos());
        item->setPos(position);
        if (!scene->isInsideBoard(event->buttonDownScenePos(Qt::LeftButton))) {
            DestinationItem* dest = new DestinationItem(QRectF(dest->rect().x(), dest->rect().y(), dest->rect().width() / 2, dest->rect().height() / 2), (ITrafficParticipantItem*)item);
            dest->setFlag(QGraphicsItem::ItemIsMovable);
        }
        // if there was a move than do next
        //((ITrafficParticipantItem*)item)->resetDestinationPosition();
    } else {
        scene->removeItem(item);
    }
}
