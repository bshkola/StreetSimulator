#include "engine.h"

Engine::Engine(const ObjectsOnMap &objectsOnMap, ICameraNoise *iCameraNoise)
    : objectsOnMap(objectsOnMap), objectsPositionUpdater(objectsOnMap.getObjects())
{
    iCameraDetection = new CameraDetectionImpl(iCameraNoise);
    //this -> objectsOnMap = objectsOnMap;
    
    finish_ = false;
    //how often Objects should be updated (milliseconds)
    millisecondsInQuantum = std::chrono::duration<int, std::milli> (100);
    //how often Cameras should make observations (milliseconds)
    camerasTrigger = std::chrono::duration<int, std::milli> (3000);
    camerasTime = std::chrono::duration<int, std::milli> (0);
}

Engine::~Engine()
{
    delete iCameraDetection;
}

void Engine::run()
{
    for(const TrafficParticipant *el: objectsOnMap.getObjects())
    {
       std::cout<<std::endl<<std::endl<<"Object: "<<std::endl;
       for(pair<int, int> el1: el->way)
       {
           std::cout<<"("<<el1.first<<", "<<el1.second<<")"<<std::endl;
       }
    }
    while(!finish_)
    {
        //save current time - start of loop
        startTime = std::chrono::duration_cast<std::chrono::milliseconds>
                    (std::chrono::high_resolution_clock::now().time_since_epoch());

        //update positions of TrafficParticipants in simulation
        objectsPositionUpdater.update();
        
        if(camerasTime >= camerasTrigger)
        {
            iCameraDetection -> calculate( objectsOnMap.getCameras(),
                                           objectsPositionUpdater.getTrafficParticipants(),
                                           database.getCameraObservation());
            database.saveMeasurent();
            
            camerasTime = std::chrono::duration<int, std::milli> (0);
        }
        else
        {
            camerasTime += millisecondsInQuantum;
        }
        
        //save current time - end of loop
        endTime = std::chrono::duration_cast<std::chrono::milliseconds>
                    (std::chrono::high_resolution_clock::now().time_since_epoch());
        //if calculations faster then quantum
        if(endTime - startTime < millisecondsInQuantum)
        {
            //sleep for rest of the quantum
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsInQuantum - (endTime - startTime)));
        }
        
    }
    std::cout << "Simulation stopped" << std::endl;
}

void Engine::finish()
{
    finish_ = true;
}

