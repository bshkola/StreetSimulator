#include "../model/convert.h"

Convert::Convert(const Board *board) : board(board)
{

}

Convert::~Convert()
{

}

Graph Convert::generateGraph()
{   //generuje graph na postawie board
    //TODO
    Graph graph;
    //listing the map
    for(int i = 0; i < board -> size_; i++)
    {   //listing rows
        for(int j = 0; j < board -> size_; j++)
        {   //listing columns
            pair<int, int> coor(i, j);
            if(graph.isExist(coor) && board -> boardMap_[i][j] == true) //if doesn't exist this vertix in the graph and on the map is mark vertix;
                graph.addVertex(coor, true);
            else    //in this position on the map didn't market the piece of street
                continue;
            if(j + 1 < board -> size_ && board -> boardMap_[i][j] == true){  //is near vertix not out of the map
                graph.addVertex(make_pair(i, j + 1), true);
                graph.addEdge(coor, 2, make_pair(i, j + 1), 0);
            }
            if(i + 1 < board -> size_ && board -> boardMap_[i][j] == true){  //is near vertix not out of the map
                graph.addVertex(make_pair(i + 1, j), true);
                graph.addEdge(coor, 3, make_pair(i + 1, j), 2);
            }
        }
    }
    return graph;
}

Graph Convert::getGraph()
{
    return graph_;
}
