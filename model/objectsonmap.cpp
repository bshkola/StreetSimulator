#include "model/objectsonmap.h"

ObjectsOnMap::ObjectsOnMap()
{

}

ObjectsOnMap::~ObjectsOnMap()
{

}

void ObjectsOnMap::addPedestrian(Cordination location, Position source, Position destination, float speed)
{
    objects.push_back(Pedestrian(location.first, location.second, speed, destination, source));
}

void ObjectsOnMap::addCar(Cordination location, Position source, Position destination, float speed)
{
    objects.push_back(Car(location.first, location.second, speed, destination, source));
}

void ObjectsOnMap::addVehicle(Cordination location, Position source, Position destination, float speed)
{
    objects.push_back(Vehicle(location.first, location.second, speed, destination, source));
}

void ObjectsOnMap::deleteObject(Cordination location, Position source, Position destinatios, float speed)
{
    //TODO
}

void ObjectsOnMap::deleteCamera(Position location, float azimuth, float angle, float range)
{
    //TODO
}
