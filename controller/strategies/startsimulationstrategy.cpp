#include "startsimulationstrategy.h"

StartSimulationStrategy::StartSimulationStrategy(ObjectsOnMap objectsOnMap):
    objectsOnMap(objectsOnMap), simulationPreparation(objectsOnMap.getBoard(), objectsOnMap.getObjects())
{

}

StartSimulationStrategy::~StartSimulationStrategy()
{

}

void StartSimulationStrategy::perform(IEvent *event)
{
    simulationPreparation.run();    //calculate way for object and building graph
}

