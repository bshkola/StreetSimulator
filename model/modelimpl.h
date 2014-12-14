#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "imodel.h"

class ModelImpl : public IModel
{
public:
    ModelImpl();
    virtual ~ModelImpl();

    Board& getBoard();

private:
     Board board;
};

#endif // MODELIMPL_H
