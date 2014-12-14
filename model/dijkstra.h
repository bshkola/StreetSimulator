#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

class Dijkstra
{
public:
    Dijkstra(const Graph &graph); //tworzy dijkstre dla danego grafu
    ~Dijkstra();

    //zwraca tablice dla symulatora: tablicaWierzcholkowPrzezKtorePrzejedzaObiekt f-cja(obiektDlaKtoregoLiczymy)
    void calculateWay(NameOfVertex source, NameOfVertex dest); //skad do kad jedziemy
private:
    Vertex selectLeastVertix();
    void calculateWeightForEdge(Vertex &ver);

    Graph graph;
};

#endif // DIJKSTRA_H
