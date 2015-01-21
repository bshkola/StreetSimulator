//Author: Andrzej Chmielowski
//Algorithm to calculate way for one object
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <deque>
#include <iostream>

#include "graph.h"
#include "../common/traffic/trafficparticipant.h"

class Dijkstra
{
    const int DISTANCE_BETWEEN_VERTECES;
public:
    Dijkstra(const Graph *graph); //tworzy dijkstre dla danego grafu
    ~Dijkstra();

    //zwraca tablice dla symulatora: tablicaWierzcholkowPrzezKtorePrzejedzaObiekt f-cja(obiektDlaKtoregoLiczymy)
    TrafficParticipant *calculateWay(TrafficParticipant *object); //skad do kad jedziemy
private:
    typedef struct Vertex_structure{
        Vertex_structure(int value, bool visited, pair<Vertex*, Vertex_structure> *before):
            visited(visited), value(value), before(before) {};
        Vertex_structure(): visited(false), value(10000000){};
        bool operator==(const struct Vertex_structure &q) const {
            if(visited != q.visited) return false;
            else if(value != q.value) return false;
            else return true;}
        bool visited;
        int value;
        pair<Vertex*, Vertex_structure> *before; //vertex which was before
    } Vertex_str;

    pair<Vertex *, Vertex_str> selectLeastVertix(list<pair<Vertex *, Vertex_str> > &avaibleVertex);
    void calculateWeightForEdge(Vertex *ver, list<pair<Vertex *, Vertex_str> > &avaibleVertex);
    void calculateValueBetweenVerteces(Vertex *sourceFun, Vertex *destFun,
                                       list<pair<Vertex *, Vertex_str> > &avaibleVertex);
    const Graph *graph;
};

#endif // DIJKSTRA_H
