#ifndef OBJECTSONMAP_H
#define OBJECTSONMAP_H

#include <list>

#include "../common/traffic/trafficparticipant.h"
#include "../common/board.h"
#include "../common/traffic/pedestrian.h"
#include "../common/traffic/car.h"
#include "../common/traffic/vehicle.h"
#include "../common/camera.h"

using namespace std;

class ObjectsOnMap
{
public:
    typedef pair<float, float> Cordination;
    typedef pair<int, int> Position;

    ObjectsOnMap();
    ~ObjectsOnMap();

    void addPedestrian(Cordination location, Position source, Position destination, float speed = 1);
    void addCar(Cordination location, Position source, Position destination, float speed = 1);
    void addVehicle(Cordination location, Position source, Position destination, float speed = 1);
    void addCamera(Position location, float azimuth, float angle, float range);
    void setCellOnField(int i, int j, bool isStreet);    //set cell on the field (true - it's street, false -it isn't street)
    void deleteObject(Cordination location, Position source, Position destinatios, float speed = 1); //erease object which has this arguments from list
    void deleteCamera(Position location, float azimuth, float angle, float range); //erase camera which has this argument from list
    list<TrafficParticipant*> getObjects();
    list<Camera*> getCameras();
    Board *getBoard();
private:
    list<TrafficParticipant*> objects;
    list<Camera*> cameras;
    Board *board;   //field of simulation
};

#endif // OBJECTSONMAP_H
