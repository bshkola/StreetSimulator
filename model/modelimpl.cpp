#include "modelimpl.h"
#include <iostream>

ModelImpl::ModelImpl()
{

}

ModelImpl::~ModelImpl()
{
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

void ModelImpl::addCar(Position coordinates) {
    objectsOnMap_.addCar(coordinates, coordinates, coordinates);
    //std::cout << "AddCar " << coordinates.first << " " << coordinates.second << std::endl;
}

void ModelImpl::replaceCar(Position oldCoordinates, Position newCoordinates) {
    objectsOnMap_.replaceObject(oldCoordinates, newCoordinates);
    //std::cout << "ReplaceCar " << oldCoordinates.first << " " << oldCoordinates.second << std::endl;
    //std::cout << "To         " << newCoordinates.first << " " << newCoordinates.second << std::endl;
}

void ModelImpl::removeCar(Position coordinates) {
    objectsOnMap_.deleteObject(coordinates, coordinates, coordinates);
    //std::cout << "RemoveCar " << coordinates.first << " " << coordinates.second << std::endl;
}
