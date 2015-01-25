//Author: Bogdan Shkola
//Implementation of PedestrianItem class
#include "../../view/items/pedestrianitem.h"
#include "../mouseeventhandler/trafficparticipansmouseeventhandler.h"

PedestrianItem::PedestrianItem(const QRectF& rect, QGraphicsItem* parent) :
    ITrafficParticipantItem(rect, parent) {

    selectedColor_ = Qt::yellow;
    unselectedColor_ = Qt::darkYellow;
}

ObjectType PedestrianItem::getTrafficObjectType() {
    return trafficObjectType_;
}

IMovableItem* PedestrianItem::clone() {
    return new PedestrianItem(this->rect());
}

MouseEventHandler* PedestrianItem::getMouseEventHandler() {
    return TrafficParticipansMouseEventHandler::getInstance();
}

