#include "engine.h"

Engine::Engine(const ObjectsOnMap &objectsOnMap, ICameraNoise *iCameraNoise): objectsOnMap(objectsOnMap)
{
    iCameraDetection = new CameraDetectionImpl(iCameraNoise);
    //this -> objectsOnMap = objectsOnMap;
}

void Engine::run()
{
    objectsPositionUpdater.update();
    iCameraDetection -> calculate(objectsOnMap.getCameras(),
                               objectsPositionUpdater.getTrafficParticipants(),
                               database.getCameraObservation());
    database.saveMeasurent();
    //TODO repaint()
}

Engine::~Engine()
{

}

