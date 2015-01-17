#include "../../view/mouseeventhandler/trafficparticipansmouseeventhandler.h"
#include "../items/destinationitem.h"
#include "../items/itrafficparticipantitem.h"
#include "../../common/events/trafficobjectaddedevent.h"
#include "../../common/events/trafficobjectreplacedevent.h"
#include "../../common/events/trafficobjectremovedevent.h"

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

            BlockingEventQueue::getInstance().push(new TrafficObjectAddedEvent(scene->getDiscreteCoordinates(event->scenePos()), item->getTrafficObjectType()));
        } else {
            BlockingEventQueue::getInstance().push(new TrafficObjectReplacedEvent(scene->getDiscreteCoordinates(event->buttonDownScenePos(Qt::LeftButton)),
                                                                        scene->getDiscreteCoordinates(event->scenePos())));
        }
        // if there was a move than do next
        //((ITrafficParticipantItem*)item)->resetDestinationPosition();
    } else {
        scene->removeItem(item);
        BlockingEventQueue::getInstance().push(new TrafficObjectRemovedEvent(scene->getDiscreteCoordinates(event->buttonDownScenePos(Qt::LeftButton))));
    }
}
