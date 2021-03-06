//Author: Bogdan Shkola
//Model representation class
#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "imodel.h"
#include "objectsonmap.h"
#include "simulationpreparator.h"
#include "../detection/cameranoiseimpl.h"

class ModelImpl : public IModel
{
public:
    ModelImpl();
    virtual ~ModelImpl();

    //Inherited methods
    void resizeBoard(int newSize);
    void addStreet(Position coordinates);
    void removeStreet(Position coordinates);
    Board& getBoard();
    void addCamera(int id, Coordinates coordinates);
    void replaceCamera(int id, Coordinates newCoordinates);
    void removeCamera(int id);
    void changeCameraOptions(int cameraId, const CameraOptions& cameraOptions);
    CameraOptions getCameraOptions(int cameraId);
    void addTrafficObject(int id, Position coordinates, ObjectType objectType);
    void replaceTrafficObject(int id, Position newCoordinates);
    void removeTrafficObject(int id);
    void replaceDestination(int trafficObjectId, Position newCoordinates);
    void startSimulation(SimulatorWindow* simulationWindow);

private:
    //Metadata of the board
    ObjectsOnMap objectsOnMap_;
};

#endif // MODELIMPL_H
