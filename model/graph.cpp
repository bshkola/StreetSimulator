#include "model/graph.h"

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::addVertex(const NameOfVertex &coor, bool isRoad)
{
    this->vertices.push_back(Vertex(coor, isRoad));
}

void Graph::addEdge(const NameOfVertex source, int si, const NameOfVertex dest, int di)
{
    list<Vertex>::iterator findSour = find(vertices.begin(), vertices.end(), source);
    list<Vertex>::iterator findDest = find(vertices.begin(), vertices.end(), dest);
    if(findSour == vertices.end() || findDest == vertices.end())
    {
        throw runtime_error("Blad przy wstawianiu krawedzi do grafu, nie ma jednego z wierzcholkow w grafie");
    }
    findSour->connect_edge(&(*findDest), di);
    findDest->connect_edge(&(*findSour), si);
}

Vertex Graph::getVertex(const NameOfVertex vert)
{
   list<Vertex>::iterator foundVertex = find(vertices.begin(), vertices.end(), vert);
   return *foundVertex;
}

Vertex Graph::end()
{

    return *(vertices.end());
}

void Vertex::connect_edge(Vertex *adjacent, int whatDirection)
{
    this->edges[whatDirection] = Edge(adjacent);
}
