#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "imodel.h"
#include "objectsonmap.h"

class ModelImpl : public IModel
{
public:
    ModelImpl();
    virtual ~ModelImpl();

    Board& getBoard();
    void addCamera(Coordinates coordinates);
    void replaceCamera(Coordinates oldCoordinates, Coordinates newCoordinates);
    void removeCamera(Coordinates coordinates);

    void addCar(Position coordinates);
    void replaceCar(Position oldCoordinates, Position newCoordinates);
    void removeCar(Position coordinates);

private:
    ObjectsOnMap objectsOnMap_;
};

#endif // MODELIMPL_H
