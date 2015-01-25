//Author: Andrzej Chmielowski, Bogdan Shkola, Wojciech Ceret
//Representing engine of simulation, move object on a window where are moving objects

#ifndef ENGINE_H
#define ENGINE_H

#include "objectspositionupdater.h"
#include "../../detection/cameradetectionimpl.h"
#include "../objectsonmap.h"
#include "../../detection/cameranoiseimpl.h"
#include "../database/database.h"
#include "../../view/simulatorwindow.h"
#include <chrono>
#include <thread>
#include <iostream>

class SimulatorWindow;

class Engine
{
public:
    Engine(const ObjectsOnMap &ObjectsOnMap, ICameraNoise *iCameraNoise, SimulatorWindow* simulationWindow);
    ~Engine();
    
    void finish();//set stop flag

    void run(); //running engine
private:
    ObjectsPositionUpdater objectsPositionUpdater; //updated objects after new update in run
    ICameraDetection *iCameraDetection; //manager cameras
    const ObjectsOnMap &objectsOnMap; //cameras on the map
    Database database; //database
    SimulatorWindow* simulationWindow_;
    //TODO referencja na widok
    
    bool finish_; //if true then stop calculations
    
    //auxillary variables for time calculations
    std::chrono::milliseconds startTime, endTime;
    std::chrono::milliseconds millisecondsInQuantum;
    std::chrono::milliseconds camerasTrigger, camerasTime;
};

#endif // ENGINE_H
