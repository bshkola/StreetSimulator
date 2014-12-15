#ifndef STARTSIMULATIONSTRATEGY_H
#define STARTSIMULATIONSTRATEGY_H

#include "../../model/objectsonmap.h"
#include "../../model/convert.h"
#include "../../model/simulationpreparator.h"
#include "istrategy.h"

class StartSimulationStrategy : public IStrategy
{
public:
    StartSimulationStrategy(ObjectsOnMap objectsOnMap);
    ~StartSimulationStrategy();
    void perform(IEvent* event);

private:
    ObjectsOnMap objectsOnMap;  //here we have list of objects on the map
    SimulationPreparator simulationPreparation; //here we calculate way for each objects and convert map to graph

};

#endif // STARTSIMULATIONSTRATEGY_H
