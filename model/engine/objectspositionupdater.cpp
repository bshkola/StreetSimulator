#include "objectspositionupdater.h"

ObjectsPositionUpdater::ObjectsPositionUpdater()
{

}

ObjectsPositionUpdater::~ObjectsPositionUpdater()
{

}

void ObjectsPositionUpdater::update()
{
    for(TrafficParticipant *el: trafficParticipants)
    {   //update all elements
        el->way.pop_front();
        el->x_ = el->way.front().first;
        el->y_ = el->way.front().second;
    }
}

list<TrafficParticipant*> &ObjectsPositionUpdater::getTrafficParticipants()
{
   return trafficParticipants;
}
