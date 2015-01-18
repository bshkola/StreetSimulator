#include "../model/convert.h"

Convert::Convert(const Board &board) : board(board)
{
    //generateGraph();
}

Convert::~Convert()
{

}

Graph *Convert::generateGraph()
{   //generuje graph na postawie board
    Graph *graph = new Graph();
    //listing the map
    for(int j = 0; j < board -> size_; j++)
    {   //listing rows
        for(int i = 0; i < board -> size_; i++)
        {   //listing columns
            pair<int, int> coor(i, j);
            if(!graph->isExist(coor) && board -> boardMap_[i][j] == true) //if doesn't exist this vertix in the graph and on the map is mark vertix;
                graph->addVertex(coor, true);
            if(j + 1 < board -> size_ && board -> boardMap_[i][j] == true && board->boardMap_[i][j+1] == true)
            {  //is near vertix not out of the map
                graph->addVertex(make_pair(i, j + 1), true);
                graph->addEdge(coor, 2, make_pair(i, j + 1), 0);
            }
            if(i + 1 < board -> size_ && board -> boardMap_[i][j] == true && board->boardMap_[i+1][j] == true)
            {  //is near vertix not out of the map
                graph->addVertex(make_pair(i + 1, j), true);
                graph->addEdge(coor, 3, make_pair(i + 1, j), 1);
            }
        }
    }
    //std::cout<<""<<graph.toString();
    return graph;
}

Graph Convert::getGraph()
{
    return graph_;
}
