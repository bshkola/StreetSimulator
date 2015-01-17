#include "../model/objectsonmap.h"
#include <iostream>

ObjectsOnMap::ObjectsOnMap() : board(8)
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

void ObjectsOnMap::addTrafficObject(Position location, ObjectType objectType)
{
    float speed = 1;

    switch (objectType) {
    case PEDESTRIAN:
        objects.push_back(new Pedestrian(location.first, location.second, speed, location, location));
        break;
    case CAR:
        objects.push_back(new Car(location.first, location.second, speed, location, location));
        break;
    case TRUCK:
        objects.push_back(new Truck(location.first, location.second, speed, location, location));
        break;
    default:
        throw exception("Wrong type of object");
    }
    for (TrafficParticipant* trafficParticipant : objects) {
        std::cout << trafficParticipant->x_ << " " << trafficParticipant->y_ << std::endl;
    }
}

void ObjectsOnMap::addCamera(Coordinates location, float azimuth, float angle, float range)
{
    cameras.push_back(new Camera(location.first, location.second, azimuth, angle, range));
    for (Camera* camera : cameras) {
        std::cout << camera->x_ << " " << camera->y_ << " " << camera->angle_ << std::endl;
    }
}

void ObjectsOnMap::setCellOnField(int i, int j, bool isStreet)
{
    board.boardMap_[i][j] = isStreet;
}

void ObjectsOnMap::replaceObject(Position oldLocation, Position newLocation)
{
    std::list<TrafficParticipant*>::iterator i = objects.begin();
    while (i != objects.end())
    {
        if ((oldLocation.first == (*i)->x_) && (oldLocation.second == (*i)->y_)) {
            (*i)->x_ = newLocation.first;
            (*i)->y_ = newLocation.second;
            break;
        }
        i++;
    }
    for (TrafficParticipant* trafficParticipant : objects) {
        std::cout << trafficParticipant->x_ << " " << trafficParticipant->y_ << std::endl;
    }
}

void ObjectsOnMap::deleteObject(Position location, Position source, Position destinatios, float speed)
{
    std::list<TrafficParticipant*>::iterator i = objects.begin();
    while (i != objects.end())
    {
        if ((location.first == (*i)->x_) && (location.second == (*i)->y_)) {
            objects.erase(i);
            break;
        }
        i++;
    }
    for (TrafficParticipant* trafficParticipant : objects) {
        std::cout << trafficParticipant->x_ << " " << trafficParticipant->y_ << std::endl;
    }
}

void ObjectsOnMap::replaceCamera(Coordinates oldCordinates, Coordinates newCordinates) {
    std::list<Camera*>::iterator i = cameras.begin();
    while (i != cameras.end())
    {
        if (abs(oldCordinates.first - (*i)->x_) + (oldCordinates.second - (*i)->y_) < 0.01) {
            (*i)->x_ = newCordinates.first;
            (*i)->y_ = newCordinates.second;
            break;
        }
        i++;
    }
    for (Camera* camera : cameras) {
        std::cout << camera->x_ << " " << camera->y_ << " " << camera->angle_ << std::endl;
    }
}


void ObjectsOnMap::deleteCamera(Coordinates location, float azimuth, float angle, float range)
{
    std::list<Camera*>::iterator i = cameras.begin();
    while (i != cameras.end())
    {
        if (abs(location.first - (*i)->x_) + (location.second - (*i)->y_) < 0.01) {
            cameras.erase(i++);
        }
        else {
            i++;
        }
    }
    for (Camera* camera : cameras) {
        std::cout << camera->x_ << " " << camera->y_ << " " << camera->angle_ << std::endl;
    }
}

void ObjectsOnMap::replaceDestination(Position oldCoordinates, Position newCoordinates, Position trafficObjectCoordinates)
{
    std::list<TrafficParticipant*>::iterator i = objects.begin();
    while (i != objects.end())
    {
        if ((trafficObjectCoordinates.first == (*i)->x_) && (trafficObjectCoordinates.second == (*i)->y_)) {
            (*i)->targetPoint_ = newCoordinates;
            break;
        }
        i++;
    }
//    for (TrafficParticipant* trafficParticipant : objects) {
//        std::cout << trafficParticipant->x_ << " " << trafficParticipant->y_ << std::endl;
//    }

    //TODO
}

list<TrafficParticipant*> ObjectsOnMap::getObjects()
{
    return objects;
}

list<Camera*> ObjectsOnMap::getCameras()
{
    return cameras;
}

Board& ObjectsOnMap::getBoard()
{
    return board;
}
