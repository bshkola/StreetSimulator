#ifndef IMODEL_H
#define IMODEL_H

#include "../common/board.h"

class IModel
{
public:
    IModel();
    virtual Board& getBoard() = 0;
};

#endif // IMODEL_H
