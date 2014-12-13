#ifndef CONVERT_H
#define CONVERT_H

#include "graph.h"

class Convert
{
public:
    Convert();
    ~Convert();

    Graph getGraph();   //zwraca graf, ktory tworzymy
private:
    Graph graph_;   //tu tworzymy graph
};

#endif // CONVERT_H
