//Author: Andrzej Chmielowski
//Ruler of converting and algorithm objects. Run converting map to graph and run calculate ways for each objects
#ifndef SIMULATIONPREPARATOR_H
#define SIMULATIONPREPARATOR_H

#include <deque>

#include "../common/board.h"
#include "convert.h"
#include "dijkstra.h"
#include "graph.h" //nameOfVertex
#include "../common/traffic/trafficparticipant.h"
#include "engine/engine.h"

class SimulationPreparator
{
public:
    SimulationPreparator(const ObjectsOnMap &objectOnMap);
    ~SimulationPreparator();

    void run(); //run the SimulationPreparator: calculate the paths and convert map to graph
private:
    Convert convert;    //converter from map to graph
    const list<TrafficParticipant*> *objects; //list of the move objects on the map
    Dijkstra *dijkstra; //algorithm for calculate the path
    list<TrafficParticipant*> waysObjects; //remember objectd and their way
    const ObjectsOnMap &objectOnMap;
};

#endif // SIMULATIONPREPARATOR_H
