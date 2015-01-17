#include "../model/dijkstra.h"

Dijkstra::Dijkstra(const Graph &graph): graph(graph)
{

}

Dijkstra::~Dijkstra()
{

}

void Dijkstra::calculateWay(TrafficParticipant *object)
{   //TODO
    NameOfVertex source = object -> startPoint_, dest = object -> targetPoint_;   //get source & destination of point
    Vertex tmp = graph.getVertex(source);
    Vertex destVertex = graph.getVertex(dest);  //finding a destination vertex
    while(tmp != destVertex || tmp != graph.end())
    {   //run dijkstra
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
    throw new exception;
    //TODO wybieramy najmniejszy z posrod nieodwiedzony grafow
    //return tmp;
}
