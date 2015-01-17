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
