#include "modelimpl.h"
#include <iostream>

ModelImpl::ModelImpl() : board(8)
{

}

ModelImpl::~ModelImpl()
{
}

Board& ModelImpl::getBoard() {
    return board;
}
