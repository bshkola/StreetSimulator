#ifndef IMODEL_H
#define IMODEL_H

#include "../common/board.h"
#include "../common/types.h"

class IModel
{
public:
    IModel();
    virtual Board& getBoard() = 0;
    virtual void addCamera(Coordinates coordinates) = 0;
    virtual void replaceCamera(Coordinates startCoordinates, Coordinates finishCoordinates) = 0;
    virtual void removeCamera(Coordinates coordinates) = 0;
};

#endif // IMODEL_H
