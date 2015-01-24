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

    void addCamera(int id, Coordinates location, float azimuth, float angle, float range);
    void replaceCamera(int id, Coordinates newCordinates); //erase camera which has this argument from list
    void deleteCamera(int id); //erase camera which has this argument from list

    void addTrafficObject(int id, Position location, ObjectType objectType);
    void replaceTrafficObject(int id, Position newLocation);
    void deleteTrafficObject(int id); //erease object which has this arguments from list

    void replaceDestination(int trafficObjectId, Position newCoordinates);

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
