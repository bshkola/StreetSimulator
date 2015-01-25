//Author: Andrzej Chmielowski, Bogdan Shkola
//Class containing metadata of the board
#ifndef OBJECTSONMAP_H
#define OBJECTSONMAP_H

#include <list>

#include "../common/traffic/trafficparticipant.h"
#include "../common/board.h"
#include "../common/traffic/pedestrian.h"
#include "../common/traffic/car.h"
#include "../common/traffic/truck.h"
#include "../common/camera.h"
#include "../common/types.h"
#include "../common/cameraoptions.h"
#include "../common/exceptions/wrongidobjectexception.h"

class ObjectsOnMap {
public:
    ObjectsOnMap();
    ~ObjectsOnMap();

    //Sets new sieze of the board
    void resizeBoard(int newSize);

    //Adds/removes the street to/from the selected coordinate
    void addStreet(Position coordinates);
    void removeStreet(Position coordinates);

    //Adds/replaces/removes the camera based on id identifier
    void addCamera(int id, Coordinates location);
    void replaceCamera(int id, Coordinates newCordinates); //erase camera which has this argument from list
    void deleteCamera(int id); //erase camera which has this argument from list

    //Change camera options (characteristics)
    void changeCameraOptions(int cameraId, const CameraOptions& cameraOptions);

    //Gets camera options (characteristics)
    CameraOptions getCameraOptions(int cameraId);

    //Adds/replaces/removes the traffic objecct based on id identifier
    void addTrafficObject(int id, Position location, ObjectType objectType);
    void replaceTrafficObject(int id, Position newLocation);
    void deleteTrafficObject(int id); //erease object which has this arguments from list

    //Replaces destination based on id identifier of the traffic object
    void replaceDestination(int trafficObjectId, Position newCoordinates);

    //Gets traffic objects on the board
    const std::list<TrafficParticipant*> &getObjects() const;

    //Gets cameras on the board
    std::list<Camera*> getCameras() const;

    //Gets the board object
    const Board &getBoard() const;
    Board &getBoard();
private:
    //Metadata of the board
    std::list<TrafficParticipant*> objects;
    std::list<Camera*> cameras;
    Board board;
};

#endif // OBJECTSONMAP_H
