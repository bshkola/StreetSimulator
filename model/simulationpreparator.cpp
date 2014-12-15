#include "model/simulationpreparator.h"

SimulationPreparator::SimulationPreparator(const Board *board, list<TrafficParticipant*> objects):
    convert(board)
{
    this->dijkstra = new Dijkstra(this->convert.generateGraph());   //generate graph and put in dijkstra
    this->objects = objects;
}


void SimulationPreparator::run()
{
    for(TrafficParticipant *obj: objects)
    {
        dijkstra->calculateWay(obj);
    }
}

SimulationPreparator::~SimulationPreparator()
{
    //destroy the objects created by constructor
    delete this->dijkstra;
}

