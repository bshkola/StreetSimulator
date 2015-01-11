#include "../model/objectsonmap.h"

ObjectsOnMap::ObjectsOnMap()
{   //empty

}

ObjectsOnMap::~ObjectsOnMap()
{
    for(TrafficParticipant *obj: objects)
    {
        delete obj;
    }
    for(Camera *obj: cameras)
    {
        delete obj;
    }
}

void ObjectsOnMap::addPedestrian(Cordination location, Position source, Position destination, float speed)
{   //done
    objects.push_back(new Pedestrian(location.first, location.second, speed, destination, source));
}

void ObjectsOnMap::addCar(Cordination location, Position source, Position destination, float speed)
{   //done
    objects.push_back(new Car(location.first, location.second, speed, destination, source));
}

void ObjectsOnMap::addTruck(Cordination location, Position source, Position destination, float speed)
{   //done
    objects.push_back(new Truck(location.first, location.second, speed, destination, source));
}

void ObjectsOnMap::setCellOnField(int i, int j, bool isStreet)
{
    board->boardMap_[i][j] = isStreet;
}

void ObjectsOnMap::deleteObject(Cordination location, Position source, Position destinatios, float speed)
{
    //TODO
}

void ObjectsOnMap::deleteCamera(Position location, float azimuth, float angle, float range)
{
    //TODO
}

list<TrafficParticipant*> ObjectsOnMap::getObjects()
{
      return objects;
}

list<Camera*> ObjectsOnMap::getCameras() const
{
    return cameras;
}

Board *ObjectsOnMap::getBoard()
{
    return board;
}
