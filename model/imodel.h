#ifndef IMODEL_H
#define IMODEL_H

#include "../common/board.h"
#include "../common/types.h"

class IModel
{
public:
    IModel();
    virtual Board& getBoard() = 0;

    virtual void addStreet(Position coordinates) = 0;
    virtual void removeStreet(Position coordinates) = 0;

    virtual void addCamera(Coordinates coordinates) = 0;
    virtual void replaceCamera(Coordinates oldCoordinates, Coordinates newCoordinates) = 0;
    virtual void removeCamera(Coordinates coordinates) = 0;

    virtual void addTrafficObject(Position coordinates, ObjectType objectType) = 0;
    virtual void replaceTrafficObject(Position oldCoordinates, Position newCoordinates) = 0;
    virtual void removeTrafficObject(Position coordinates) = 0;

    virtual void replaceDestination(Position oldCoordinates, Position newCoordinates, Position trafficObjectCoordinates) = 0;

    virtual void startSimulation() = 0;

};

#endif // IMODEL_H
