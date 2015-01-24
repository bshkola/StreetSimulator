#ifndef OBJECTSPOSITIONUPDATER_H
#define OBJECTSPOSITIONUPDATER_H


#include <list>
#include <deque>

#include "../../common/traffic/trafficparticipant.h"
#include "../graph.h"

using namespace std;

class ObjectsPositionUpdater
{
public:
    ObjectsPositionUpdater(list<TrafficParticipant*> trafficParticipants);
    ~ObjectsPositionUpdater();

    bool update(); //do next step's position's objects
    list<TrafficParticipant*> &getTrafficParticipants();
    list<NameOfVertex> getPresentPositionObjects(); //TODO where is implementation
private:
    list<TrafficParticipant*> trafficParticipants;
};

#endif // OBJECTSPOSITIONUPDATER_H
