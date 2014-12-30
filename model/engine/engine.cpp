#include "engine.h"

Engine::Engine(const ObjectsOnMap &objectsOnMap, ICameraNoise *iCameraNoise): objectsOnMap(objectsOnMap)
{
    iCameraDetection = new CameraDetectionImpl(iCameraNoise);
    //this -> objectsOnMap = objectsOnMap;
    
    finish_ = false;
    millisecondsInQuantum = std::chrono::duration<int, std::milli> (100);
}

Engine::~Engine()
{
    delete iCameraDetection;
}

void Engine::run()
{
    while(!finish_)
    {
        //TODO startTime = getTime();
        startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch());

        objectsPositionUpdater.update();
        iCameraDetection -> calculate( objectsOnMap.getCameras(),
                                       objectsPositionUpdater.getTrafficParticipants(),
                                       database.getCameraObservation());
        database.saveMeasurent();
        //TODO repaint()
        
        //TODO wait(getTime() - startTime);
        endTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch());
        if(endTime - startTime < millisecondsInQuantum)
        {
            //TODO wait(getTime() - startTime);
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsInQuantum - (endTime - startTime)));
        }
        
    }
    std::cout << "Simulation stopped" << std::endl;
}

void Engine::finish()
{
    finish_ = true;
}

