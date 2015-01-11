#ifndef OBJECTSPOSITIONUPDATER_H
#define OBJECTSPOSITIONUPDATER_H


#include <list>

#include "../../common/traffic/trafficparticipant.h"

using namespace std;

class ObjectsPositionUpdater
{
public:
    ObjectsPositionUpdater();
    ~ObjectsPositionUpdater();

    void update(); //do next step's position's objects
    list<TrafficParticipant*> &getTrafficParticipants();
private:
    list<TrafficParticipant*> trafficParticipants;
};

#endif // OBJECTSPOSITIONUPDATER_H
