#include "../model/modelimpl.h"
#include <iostream>

ModelImpl::ModelImpl()
{
    std::cout << "ModelImpl()" << std::endl;
}

ModelImpl::~ModelImpl()
{
    std::cout << "~ModelImpl()" << std::endl;
}

void ModelImpl::addStreet(Position coordinates) {
    objectsOnMap_.addStreet(coordinates);
}

void ModelImpl::removeStreet(Position coordinates) {
    objectsOnMap_.removeStreet(coordinates);
}

Board& ModelImpl::getBoard() {
    return objectsOnMap_.getBoard();
}

void ModelImpl::addCamera(Coordinates coordinates) {
    objectsOnMap_.addCamera(coordinates, 0, 0, 0);
}

void ModelImpl::replaceCamera(Coordinates oldCoordinates, Coordinates newCoordinates) {
    objectsOnMap_.replaceCamera(oldCoordinates, newCoordinates);
}

void ModelImpl::removeCamera(Coordinates coordinates) {
    objectsOnMap_.deleteCamera(coordinates, 0, 0, 0);
}

void ModelImpl::addTrafficObject(Position coordinates, ObjectType objectType) {
    objectsOnMap_.addTrafficObject(coordinates, objectType);
    //std::cout << "AddCar " << coordinates.first << " " << coordinates.second << std::endl;
}

void ModelImpl::replaceTrafficObject(Position oldCoordinates, Position newCoordinates) {
    objectsOnMap_.replaceObject(oldCoordinates, newCoordinates);
    //std::cout << "ReplaceCar " << oldCoordinates.first << " " << oldCoordinates.second << std::endl;
    //std::cout << "To         " << newCoordinates.first << " " << newCoordinates.second << std::endl;
}

void ModelImpl::removeTrafficObject(Position coordinates) {
    objectsOnMap_.deleteObject(coordinates, coordinates, coordinates);
    //std::cout << "RemoveCar " << coordinates.first << " " << coordinates.second << std::endl;
}

void ModelImpl::replaceDestination(Position oldCoordinates, Position newCoordinates, Position trafficObjectCoordinates) {
    objectsOnMap_.replaceDestination(oldCoordinates, newCoordinates, trafficObjectCoordinates);
//    std::cout << "ReplaceCar " << oldCoordinates.first << " " << oldCoordinates.second << std::endl;
//    std::cout << "To         " << newCoordinates.first << " " << newCoordinates.second << std::endl;
//    std::cout << "Parent     " << trafficObjectCoordinates.first << " " << trafficObjectCoordinates.second << std::endl;
}

void ModelImpl::startSimulation() {
    //TODO
    SimulationPreparator simulationPreparator(objectsOnMap_);
    try
    {
        simulationPreparator.run();
        Engine engine(simulationPreparator.getObjectOnMap(), NULL);
        engine.run();
    }
    catch(NotWayBetweenSourceAndDestinationTargetPointExceptions ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
}
