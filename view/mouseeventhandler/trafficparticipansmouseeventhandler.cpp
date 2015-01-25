#include "../../view/mouseeventhandler/trafficparticipansmouseeventhandler.h"
#include "../items/destinationitem.h"
#include "../items/itrafficparticipantitem.h"
#include "../../common/events/trafficobjectaddedevent.h"
#include "../../common/events/trafficobjectreplacedevent.h"
#include "../../common/events/trafficobjectremovedevent.h"

int TrafficParticipansMouseEventHandler::indexCounter = 0;

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
    ITrafficParticipantItem* trafficParticipantItem = static_cast<ITrafficParticipantItem*>(item);

    if (scene->isInsideBoard(event->scenePos())) {
        QPointF position = scene->getDiscretePosition(event->scenePos());
        item->setPos(position);
        if (!scene->isInsideBoard(event->buttonDownScenePos(Qt::LeftButton))) {
            DestinationItem* dest = new DestinationItem(QRectF(item->rect().x(), item->rect().y(), item->rect().width() / 2, item->rect().height() / 2), (ITrafficParticipantItem*)item);
            dest->setFlag(QGraphicsItem::ItemIsMovable);

            trafficParticipantItem->setId(indexCounter);
            BlockingEventQueue::getInstance().push(new TrafficObjectAddedEvent(indexCounter++, scene->getDiscreteCoordinates(event->scenePos()), item->getTrafficObjectType()));
        } else {
            BlockingEventQueue::getInstance().push(
                        new TrafficObjectReplacedEvent(trafficParticipantItem->getId(), scene->getDiscreteCoordinates(event->scenePos())));
        }
    } else {
        scene->removeItem(item);
        if (scene->isInsideBoard(event->buttonDownScenePos(Qt::LeftButton))) {
            BlockingEventQueue::getInstance().push(new TrafficObjectRemovedEvent(trafficParticipantItem->getId()));
        }
    }
}
