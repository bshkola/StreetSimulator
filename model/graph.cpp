#include "../model/graph.h"

Graph::Graph()
{   //empty

}

Graph::~Graph()
{   //empty, we have local vertex not dynamic

}

void Graph::addVertex(const NameOfVertex &coor, bool isRoad)
{   //done
    this->vertices.push_back(Vertex(coor, isRoad));
}

void Graph::addEdge(const NameOfVertex source, int si, const NameOfVertex dest, int di)
{   //done
    list<Vertex>::iterator findSour = find(vertices.begin(), vertices.end(), source);
    list<Vertex>::iterator findDest = find(vertices.begin(), vertices.end(), dest);
    if(findSour == vertices.end() || findDest == vertices.end())
    {
        throw runtime_error("Error trying insert edge into graph, doesn't exist vertex which is on end of one edge");
    }
    findSour->connect_edge(&(*findDest), di);
    findDest->connect_edge(&(*findSour), si);
}

Vertex Graph::getVertex(const NameOfVertex vert)
{   //done
   list<Vertex>::iterator foundVertex = find(vertices.begin(), vertices.end(), vert);
   return *foundVertex;
}

Vertex Graph::end()
{   //done
    return *(vertices.end());
}

void Vertex::connect_edge(Vertex *adjacent, int whatDirection)
{   //done
    this->edges[whatDirection] = Edge(adjacent);
}
