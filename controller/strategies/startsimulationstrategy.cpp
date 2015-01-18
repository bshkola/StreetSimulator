#include "startsimulationstrategy.h"

StartSimulationStrategy::StartSimulationStrategy(ObjectsOnMap objectsOnMap):
    objectsOnMap(objectsOnMap), simulationPreparation(objectsOnMap)
{

}

StartSimulationStrategy::~StartSimulationStrategy()
{

}

void StartSimulationStrategy::perform(IEvent *event)
{
    simulationPreparation.run();    //calculate way for object and building graph
}

