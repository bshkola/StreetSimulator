//Author: Andrzej Chmielowski
//Ruler of converting and algorithm objects. Run converting map to graph and run calculate ways for each objects
#ifndef SIMULATIONPREPARATOR_H
#define SIMULATIONPREPARATOR_H

#include "../common/board.h"
#include "convert.h"
#include "dijkstra.h"
#include "../common/traffic/trafficparticipant.h"

class SimulationPreparator
{
public:
    SimulationPreparator(const Board &board, list<TrafficParticipant*> objects);
    ~SimulationPreparator();

    void run(); //run the SimulationPreparator: calculate the paths and convert map to graph
private:
    Convert convert;    //converter from map to graph
    list<TrafficParticipant*> objects; //list of the move objects on the map
    Dijkstra *dijkstra; //algorithm for calculate the path
};

#endif // SIMULATIONPREPARATOR_H
