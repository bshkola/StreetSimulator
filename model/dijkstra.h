#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

class Dijkstra
{
public:
    Dijkstra(const Graph graph); //tworzy dijkstre dla danego grafu
    ~Dijkstra();

    void calculateWay();    //zwraca tablice dla symulatora: tablicaWierzcholkowPrzezKtorePrzejedzaObiekt f-cja(obiektDlaKtoregoLiczymy)
};

#endif // DIJKSTRA_H
