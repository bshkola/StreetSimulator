#include "model/dijkstra.h"

Dijkstra::Dijkstra(const Graph &graph): graph(graph)
{

}

Dijkstra::~Dijkstra()
{

}

void Dijkstra::calculateWay(NameOfVertex source, NameOfVertex dest)
{
    Vertex tmp = graph.getVertex(source);
    Vertex destVertex = graph.getVertex(dest);  //wierzcholke docelowy
    while(tmp != destVertex || tmp != graph.end())
    {   //wykonujemy dijkstre
        calculateWeightForEdge(tmp);
        tmp = selectLeastVertix();
    }
}

void Dijkstra::calculateWeightForEdge(Vertex &ver)
{
    //TODO obliczamy ile kosztuje przejscie do kazdego wierzcholka polaczonego krawedzia
}

Vertex Dijkstra::selectLeastVertix()
{

    //TODO wybieramy najmniejszy z posrod nieodwiedzony grafow
    //return tmp;
}
