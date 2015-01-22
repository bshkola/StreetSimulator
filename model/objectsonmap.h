//Author: Andrzej Chmielowski
//Remember object put on the map in View
#ifndef OBJECTSONMAP_H
#define OBJECTSONMAP_H

#include <list>

#include "../common/traffic/trafficparticipant.h"
#include "../common/board.h"
#include "../common/traffic/pedestrian.h"
#include "../common/traffic/car.h"
#include "../common/traffic/vehicle.h"
#include "../common/camera.h"
#include "../common/types.h"

using namespace std;

class ObjectsOnMap
{
public:

    ObjectsOnMap();
    ~ObjectsOnMap();

    void addStreet(Position coordinates);
    void removeStreet(Position coordinates);

    //void addPedestrian(Position location, Position source, Position destination, float speed = 1);
    void addTrafficObject(Position location, ObjectType objectType);
    //void addTruck(Position location, Position source, Position destination, float speed = 1);
    void addCamera(Coordinates location, float azimuth, float angle, float range);
    void setCellOnField(int i, int j, bool isStreet);    //set cell on the field (true - it's street, false -it isn't street)

    void replaceObject(Position oldLocation, Position newLocation);
    void deleteObject(Position location, Position source, Position destinatios, float speed = 1); //erease object which has this arguments from list
    void replaceCamera(Coordinates oldCordinates, Coordinates newCordinates); //erase camera which has this argument from list
    void deleteCamera(Coordinates location, float azimuth, float angle, float range); //erase camera which has this argument from list
    void replaceDestination(Position oldCoordinates, Position newCoordinates, Position trafficObjectCoordinates);

    const list<TrafficParticipant*> &getObjects() const;
    list<Camera*> getCameras() const;
    const Board &getBoard() const;
    Board &getBoard();
private:
    list<TrafficParticipant*> objects;
    list<Camera*> cameras;
    Board board;   //field of simulation
};

#endif // OBJECTSONMAP_H
