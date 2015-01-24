#include "../model/simulationpreparator.h"

SimulationPreparator::SimulationPreparator(const ObjectsOnMap &objectOnMap):
    convert(objectOnMap.getBoard()), objectOnMap(objectOnMap), objects(objectOnMap.getObjects())
{
    this->dijkstra = new Dijkstra(this->convert.generateGraph());   //generate graph and put in dijkstra
}


void SimulationPreparator::run()
{    
    for(TrafficParticipant *obj: objects)
    {
        waysObjects.push_back(dijkstra->calculateWay(obj));
    }
    //test
        //Engine engine(this->objectOnMap, NULL);
       // engine.run();
    //end test
}

SimulationPreparator::~SimulationPreparator()
{
    //destroy the objects created by constructor
    delete this->dijkstra;
}

const ObjectsOnMap &SimulationPreparator::getObjectOnMap() const
{
    return objectOnMap;
}

