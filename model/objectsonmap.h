#ifndef OBJECTSONMAP_H
#define OBJECTSONMAP_H

#include <list>

#include "../common/traffic/trafficparticipant.h"
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
    void deleteObject(Cordination location, Position source, Position destinatios, float speed = 1); //erease object which has this arguments from list
    void deleteCamera(Position location, float azimuth, float angle, float range); //erase camera which has this argument from list
private:
    list<TrafficParticipant> objects;
    list<Camera> cameras;
};

#endif // OBJECTSONMAP_H
