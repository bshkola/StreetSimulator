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

void ModelImpl::resizeBoard(int newSize) {
    objectsOnMap_.resizeBoard(newSize);
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

void ModelImpl::addCamera(int id, Coordinates coordinates) {
    objectsOnMap_.addCamera(id, coordinates);
}

void ModelImpl::replaceCamera(int id, Coordinates newCoordinates) {
    objectsOnMap_.replaceCamera(id, newCoordinates);
}

void ModelImpl::removeCamera(int id) {
    objectsOnMap_.deleteCamera(id);
}

void ModelImpl::changeCameraOptions(int cameraId, const CameraOptions& cameraOptions) {
    objectsOnMap_.changeCameraOptions(cameraId, cameraOptions);
}

CameraOptions ModelImpl::getCameraOptions(int cameraId) {
    return objectsOnMap_.getCameraOptions(cameraId);
}

void ModelImpl::addTrafficObject(int id, Position coordinates, ObjectType objectType) {
    objectsOnMap_.addTrafficObject(id, coordinates, objectType);
}

void ModelImpl::replaceTrafficObject(int id, Position newCoordinates) {
    objectsOnMap_.replaceTrafficObject(id, newCoordinates);
}

void ModelImpl::removeTrafficObject(int id) {
    objectsOnMap_.deleteTrafficObject(id);
}

void ModelImpl::replaceDestination(int trafficObjectId, Position newCoordinates) {
    objectsOnMap_.replaceDestination(trafficObjectId, newCoordinates);
}

void ModelImpl::startSimulation(SimulatorWindow* simulationWindow) {
    try
    {
        ICameraNoise* cameraNoise = new CameraNoiseImpl();
        SimulationPreparator simulationPreparator(objectsOnMap_);
        simulationPreparator.run();
        simulationWindow->showSignal();
        Engine engine(simulationPreparator.getObjectOnMap(), cameraNoise, simulationWindow);\
        engine.run();
    }
    catch(NotWayBetweenSourceAndDestinationTargetPointExceptions ex)
    {
        std::cout<<ex.what()<<std::endl;
    }
}
