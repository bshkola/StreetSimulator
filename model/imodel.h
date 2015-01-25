//Author: Bogdan Shkola
//Model interface for MVC template
#ifndef IMODEL_H
#define IMODEL_H

#include "../common/board.h"
#include "../common/types.h"
#include "../view/simulatorwindow.h"
#include "../common/cameraoptions.h"

class IModel {
public:
    IModel() {}
    //Gets the board object
    virtual Board& getBoard() = 0;

    //Sets new sieze of the board
    virtual void resizeBoard(int newSize) = 0;

    //Adds/removes the street to/from the selected coordinate
    virtual void addStreet(Position coordinates) = 0;
    virtual void removeStreet(Position coordinates) = 0;

    //Adds/replaces/removes the camera based on id identifier
    virtual void addCamera(int id, Coordinates coordinates) = 0;
    virtual void replaceCamera(int id, Coordinates newCoordinates) = 0;
    virtual void removeCamera(int id) = 0;

    //Change camera options (characteristics)
    virtual void changeCameraOptions(int cameraId, const CameraOptions& cameraOptions) = 0;

    //Gets camera options (characteristics)
    virtual CameraOptions getCameraOptions(int cameraId) = 0;

    //Adds/replaces/removes the traffic objecct based on id identifier
    virtual void addTrafficObject(int id, Position coordinates, ObjectType objectType) = 0;
    virtual void replaceTrafficObject(int id, Position newCoordinates) = 0;
    virtual void removeTrafficObject(int id) = 0;

    //Replaces destination based on id identifier of the traffic object
    virtual void replaceDestination(int trafficObjectId, Position newCoordinates) = 0;

    //Starts simulation algorithm
    virtual void startSimulation(SimulatorWindow* simulationWindow) = 0;
};

#endif // IMODEL_H
