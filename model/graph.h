//Author: Andrzej Chmielowski
//Implementation of graph
#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <sstream>
#include <iostream>

using namespace  std;

class Vertex;
typedef pair<int, int> NameOfVertex; //nazwa wierzcholka, nazwa wierzcholka sa to wspolrzedne go na mapie

class Graph
{
public:
    Graph();
    ~Graph();

    void addVertex(const NameOfVertex &coor, bool isRoad); //dodaje nowy wierzcholyk do grafu
    bool isExist(const NameOfVertex &coor) const; //is this vertix already exist in Graph?
    void addEdge(const NameOfVertex source, int si, const NameOfVertex dest, int di); //dodaje krawedz pomiedzy wierzcholkami,
        //si di - mowia pod ktory numer dodajemy dana krawedz np si = 2 ==> edge[2] = source
    Vertex *getVertex(const NameOfVertex vert) const; //zwraca wierzcholek o tych koordynatach

    Vertex *end() const;
    string toString() const;
     // Private methods and member variables
private:
    list<Vertex*>::const_iterator find(const NameOfVertex &nameVertex) const; //find vertex by name

    list<Vertex*> vertices;  //przchowuje wierzcholki
};

struct Edge
{
  Edge(): m_Edge(NULL){};
  Edge(Vertex *edge) :m_Edge(edge){}
  Vertex *m_Edge;
}; // END EDGE

class Vertex
{
public:
  Vertex (): name(make_pair(-1, -1)), isRoad(false) {};
  Vertex(const NameOfVertex name, bool isRoad):name(name), isRoad(isRoad){ };
  void connect_edge(Vertex *adjacent, int whatDirection); //adjacent - do jakiego ver laczymy, whatDirection - w jakim kierunku jest edge
  const NameOfVertex getName() { return name; };
  void getType() const;  //mowi jakiego typu jest dany wierzcholek
  const Edge &getEdge(const int number) const {return edges[number];};    //zwraca krawedz 0-3
  int operator==(const Vertex &q) const {return name == q.name;}
  int operator==(const Vertex *q) const {return name == q->name;}
  int operator==(const NameOfVertex &q) const {return name == q;}
  bool operator!=(const Vertex &q) const {return name != q.name;}
  bool operator!=(const Vertex *q) const {return name != q->name;}

private:
  //type
  Edge edges[4];    //mozemy miec tylko 4 krawedzie
  NameOfVertex name;
  bool isRoad;     //mowi czy dany wierzcholek jest odcinkiem drogi, czy czyms innym
}; // END VERTE

//structure for equelst structure
template <typename T1, typename T2>
struct pointer_values_equal
{
    const T1* to_find;

    bool operator == (const T2* other) const
    {
        return *to_find == other->name;
    }
};

#endif // GRAPH_H
