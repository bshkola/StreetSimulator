#include "../model/objectsonmap.h"
#include <cmath>
#include <iostream>

ObjectsOnMap::ObjectsOnMap() : board(8)
{   
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

void ObjectsOnMap::addStreet(Position coordinates) { // TODO check if inside the board
    board.boardMap_[coordinates.first][coordinates.second] = true;
}

void ObjectsOnMap::removeStreet(Position coordinates) {
    board.boardMap_[coordinates.first][coordinates.second] = false;
}

void ObjectsOnMap::addTrafficObject(int id, Position location, ObjectType objectType)
{
    float speed = 1;

    switch (objectType) {
    case PEDESTRIAN:
        objects.push_back(new Pedestrian(id, speed, location, location));
        break;
    case CAR:
        objects.push_back(new Car(id, speed, location, location));
        break;
    case TRUCK:
        objects.push_back(new Truck(id, speed, location, location));
        break;
    default:
        throw exception();
    }
    for (TrafficParticipant* trafficParticipant : objects) {
        std::cout << trafficParticipant->x_ << " " << trafficParticipant->y_ << std::endl;
    }
}

void ObjectsOnMap::replaceTrafficObject(int id, Position newLocation)
{
    for (TrafficParticipant* trafficParticipant : objects) {
        if (trafficParticipant->id_ == id) {
            trafficParticipant->x_ = newLocation.first;
            trafficParticipant->y_ = newLocation.second;
            return;
        }
    }
    throw std::exception("wrong id"); //TODO add exception
}

void ObjectsOnMap::deleteTrafficObject(int id)
{
    for (TrafficParticipant* trafficParticipant : objects) {
        if (trafficParticipant->id_ == id) {
            objects.remove(trafficParticipant);
            return;
        }
    }
    throw std::exception("wrong id"); //TODO add exception
}

void ObjectsOnMap::addCamera(int id, Coordinates location, float azimuth, float angle, float range)
{
    cameras.push_back(new Camera(id, location.first, location.second, azimuth, angle, range));
    for (Camera* camera : cameras) {
        std::cout << camera->x_ << " " << camera->y_ << " " << camera->angle_ << std::endl;
    }
}

void ObjectsOnMap::replaceCamera(int id, Coordinates newCordinates) {
    for (Camera* camera : cameras) {
        if (camera->id_ == id) {
            camera->x_ = newCordinates.first;
            camera->y_ = newCordinates.second;
            return;
        }
    }
    throw std::exception("wrong id"); //TODO add exception
}

CameraOptions ObjectsOnMap::getCameraOptions(int cameraId) {
    for (Camera* camera : cameras) {
        if (camera->id_ == cameraId) {
            return CameraOptions(camera->angle_, camera->azimuth_, camera->range_);
        }
    }
    throw std::exception("wrong id"); //TODO add exception
}


void ObjectsOnMap::deleteCamera(int id)
{
    for (Camera* camera : cameras) {
        if (camera->id_ == id) {
            cameras.remove(camera);
            return;
        }
    }
    throw std::exception("wrong id"); //TODO add exception
}

void ObjectsOnMap::changeCameraOptions(int cameraId, const CameraOptions& cameraOptions) {
    for (Camera* camera : cameras) {
        if (camera->id_ == cameraId) {
            camera->angle_ = cameraOptions.getAngle();
            camera->azimuth_ = cameraOptions.getDirection();
            camera->range_ = cameraOptions.getRange();
            return;
        }
    }
    throw std::exception("wrong id"); //TODO add exception
}


void ObjectsOnMap::replaceDestination(int trafficObjectId, Position newCoordinates)
{
    for (TrafficParticipant* trafficParticipant : objects) {
        if (trafficParticipant->id_ == trafficObjectId) {
            trafficParticipant->targetPoint_ = newCoordinates;
            return;
        }
    }
    throw std::exception("wrong id"); //TODO add exception
}

const list<TrafficParticipant*> &ObjectsOnMap::getObjects() const
{
    return objects;
}

list<Camera*> ObjectsOnMap::getCameras() const
{
    return cameras;
}

const Board &ObjectsOnMap::getBoard() const
{
    return board;
}

Board &ObjectsOnMap::getBoard()
{
    return board;
}
