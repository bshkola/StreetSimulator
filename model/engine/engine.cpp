#include "engine.h"


Engine::Engine(const ObjectsOnMap &objectsOnMap, ICameraNoise *iCameraNoise, SimulatorWindow* simulationWindow)
    : objectsOnMap(objectsOnMap), objectsPositionUpdater(objectsOnMap.getObjects())
{
    iCameraDetection = new CameraDetectionImpl(iCameraNoise);
    //this -> objectsOnMap = objectsOnMap;
    simulationWindow_ = simulationWindow;
    simulationWindow_->initCloseWindowHandler(this);
    finish_ = false;
    //how often Objects should be updated (milliseconds)
    millisecondsInQuantum = std::chrono::duration<int, std::milli> (1500);
    //how often Cameras should make observations (milliseconds)
    camerasTrigger = std::chrono::duration<int, std::milli> (3000);
    camerasTime = std::chrono::duration<int, std::milli> (0);

    simulationWindow_->showBoardSignal(objectsOnMap.getBoard());
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
       std::cout << el->x_ << "  " << el->y_ << std::endl;

       /*for(pair<int, int> el1: el->way)
       {
           std::cout<<"("<<el1.first<<", "<<el1.second<<")"<<std::endl;
       }*/
    }

    list<TrafficParticipant*> copy = objectsOnMap.getObjects();

    simulationWindow_->showTrafficSignal(copy);

    std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsInQuantum));

    while(!finish_)
    {
        //save current time - start of loop
        startTime = std::chrono::duration_cast<std::chrono::milliseconds>
                    (std::chrono::high_resolution_clock::now().time_since_epoch());

        //update positions of TrafficParticipants in simulation
        objectsPositionUpdater.update();

        for (TrafficParticipant* trafficParticipant : objectsPositionUpdater.getTrafficParticipants()) {
            std::cout << "Part: " << trafficParticipant->x_ << " " << trafficParticipant->y_ << std::endl;
        }
        simulationWindow_->updateViewSignal(objectsPositionUpdater.getTrafficParticipants());

        if(camerasTime >= camerasTrigger)
        {
            iCameraDetection -> calculate( objectsOnMap.getCameras(),
                                           objectsPositionUpdater.getTrafficParticipants(),
                                           database.getCameraObservation(),
                                           objectsOnMap.getBoard().size_);
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

