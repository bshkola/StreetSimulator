#include "engine.h"

Engine::Engine(const ObjectsOnMap &objectsOnMap, ICameraNoise *iCameraNoise): objectsOnMap(objectsOnMap)
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
        
        //TODO repaint()
        //////////////////////////////////TEST//////WYWALIC////////////
        //jest zrobione zamiast przerysowanie mapy, repaint w konsoli
        //test paint map
        /*
        for(int i = 0; i < objectsOnMap.getBoard()->size_; i++)
            std::cout<<i;
        std::cout<<endl;
        for(int i = 0; i < objectsOnMap.getBoard()->size_; i++)
        {
            std::cout<<i;
            for(int j = 0; j < objectsOnMap.getBoard()->size_; j++)
            {
                bool isObjectHere = false;
                for(TrafficParticipant* el: *objectsOnMap.getObjects())
                {
                    if(el->x == j && el->y == i)
                        isObjectHere = true;
                }
                if(objectsOnMap.getBoard()->boardMap_[i][j] == true)
                {
                    if(!isObjectHere)
                        std::cout<<"+";
                    else
                        std::cout<<"*";
                }
                else
                {
                    if(!isObjectHere)
                        std::cout<<"#";
                    else
                        std::cout<<"*";
                }
            }
            std::cout<<std::endl;
        }
        cout<<"Objects" <<endl;
        for(TrafficParticipant* el: *objectsOnMap.getObjects())
        {
            for(std::pair<int, int> obj: el->way)
                cout<<"way x: " <<obj.first<<" y: "<<obj.second<<endl;
        }
        cout<<"Endl objects"<<endl;
        int i;
        std::cin>>i;
        */
        //end test paint map
        //////////////////////////////////TEST//////WYWALIC dotad////////////
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

