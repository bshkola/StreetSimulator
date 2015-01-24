#include "objectspositionupdater.h"

ObjectsPositionUpdater::ObjectsPositionUpdater(list<TrafficParticipant *> trafficParticipants)
    : trafficParticipants(trafficParticipants)
{

}

ObjectsPositionUpdater::~ObjectsPositionUpdater()
{

}

bool ObjectsPositionUpdater::update()
{
    bool isFinish = true;
    for(TrafficParticipant *el: trafficParticipants)
    {   //update all elements
        if(!(el -> way.empty()))
        {
            el->xBefore_ = el->way.front().first;
            el->yBefore_ = el->way.front().second;
            el->way.pop_front();
            if(!(el -> way.empty()))
            {   //has object next position
                el->x_ = el->way.front().first;
                el->y_ = el->way.front().second;
                isFinish = false;
            }
            else
            {
                el->x_ = el->xBefore_;
                el->y_ = el->yBefore_;
            }
        }
        std::cout<<"Object foo moved: (" << el->xBefore_ << ", " << el->yBefore_ <<") ->>> ("
                << el->x_ <<", " << el->y_ <<")"<<std::endl; //only test, delete after
    }
    std::cout<<"Updated position objects is finish: " << isFinish <<std::endl<<std::endl; //only for test, delete after
    return isFinish;
}

list<TrafficParticipant*> &ObjectsPositionUpdater::getTrafficParticipants()
{
   return trafficParticipants;
}
