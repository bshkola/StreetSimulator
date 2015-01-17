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
    void replaceCamera(Coordinates startCoordinates, Coordinates finishCoordinates);
    void removeCamera(Coordinates coordinates);

private:
    ObjectsOnMap objectsOnMap_;
};

#endif // MODELIMPL_H
