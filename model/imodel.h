#ifndef IMODEL_H
#define IMODEL_H

#include "../common/board.h"
#include "../common/types.h"
#include "../view/simulatorwindow.h"
#include "../common/cameraoptions.h"

class IModel
{
public:
    IModel();
    virtual Board& getBoard() = 0;

    virtual void addStreet(Position coordinates) = 0;
    virtual void removeStreet(Position coordinates) = 0;

    virtual void addCamera(int id, Coordinates coordinates) = 0;
    virtual void replaceCamera(int id, Coordinates newCoordinates) = 0;
    virtual void removeCamera(int id) = 0;

    virtual void changeCameraOptions(int cameraId, const CameraOptions& cameraOptions) = 0;
    virtual CameraOptions getCameraOptions(int cameraId) = 0;

    virtual void addTrafficObject(int id, Position coordinates, ObjectType objectType) = 0;
    virtual void replaceTrafficObject(int id, Position newCoordinates) = 0;
    virtual void removeTrafficObject(int id) = 0;

    virtual void replaceDestination(int trafficObjectId, Position newCoordinates) = 0;

    virtual void startSimulation(SimulatorWindow* simulationWindow) = 0;

};

#endif // IMODEL_H
