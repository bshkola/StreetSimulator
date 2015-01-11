#ifndef ENGINE_H
#define ENGINE_H

#include "objectspositionupdater.h"
#include "../../detection/cameradetectionimpl.h"
#include "../objectsonmap.h"
#include "../../detection/cameranoiseimpl.h"
#include "../database/database.h"
class Engine
{
public:
    Engine(const ObjectsOnMap &ObjectsOnMap, ICameraNoise *iCameraNoise);
    ~Engine();

    void run(); //running engine
private:
    ObjectsPositionUpdater objectsPositionUpdater; //updated objects after new update in run
    ICameraDetection *iCameraDetection; //manager cameras
    const ObjectsOnMap &objectsOnMap; //cameras on the map
    Database database; //database
    //TODO referencja na widok
};

#endif // ENGINE_H
