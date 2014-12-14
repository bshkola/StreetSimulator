#include "model/convert.h"

Convert::Convert(const Board &board) : board(board)
{

}

Convert::~Convert()
{

}

Graph Convert::generateGraph()
{   //generuje graph na postawie board
    Graph graph;
    return graph;
}

Graph Convert::getGraph()
{
    return graph_;
}
