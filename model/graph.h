#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <list>

#include "../common/coordinates.h"

using namespace  std;

class vertex;

class Graph
{
public:
    Graph();
    ~Graph();

    void addVertix(const Coordinates coor); //dodaje nowy wierzcholyk do grafu
    void addEdge(const Coordinates source, const Coordinates dest); //dodaje krawedz pomiedzy wierzcholkami, jednoczesnie zmiena typ source wierzcholka
    void getVertix(const Coordinates vert); //zwraca wierzcholek o tych koordynatach

     // Private methods and member variables
     private:
        list<vertex> vertices;  //przchowuje wierzcholki
};


struct edge
{
  edge(vertex *edge) :
    m_Edge(edge)
    {}
  vertex *m_Edge;
}; // END EDGE

class vertex
{
public:
  vertex(Coordinates name) :
    name(name)
  {}
  void connect_edge(vertex *adjacent);
  const Coordinates getName();
  const void getType();  //mowi jakiego typu jest dany wierzcholek
  const list<edge> &getEdges();

private:
  //type
  list<edge> m_Edges;
  Coordinates name;
}; // END VERTE
#endif // GRAPH_H
