#include "../../view/mouseeventhandler/trafficparticipansmouseeventhandler.h"
#include "../items/destinationitem.h"
#include "../items/itrafficparticipantitem.h"
#include "../../common/events/caraddedevent.h"
#include "../../common/events/carreplacedevent.h"
#include "../../common/events/carremovedevent.h"

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

            BlockingEventQueue::getInstance().push(new CarAddedEvent(scene->getDiscreteCoordinates(event->scenePos())));
        } else {
            BlockingEventQueue::getInstance().push(new CarReplacedEvent(scene->getDiscreteCoordinates(event->buttonDownScenePos(Qt::LeftButton)),
                                                                        scene->getDiscreteCoordinates(event->scenePos())));
        }
        // if there was a move than do next
        //((ITrafficParticipantItem*)item)->resetDestinationPosition();
    } else {
        scene->removeItem(item);
        BlockingEventQueue::getInstance().push(new CarRemovedEvent(scene->getDiscreteCoordinates(event->buttonDownScenePos(Qt::LeftButton))));
    }
}
