#ifndef CONVERT_H
#define CONVERT_H

#include "../common/board.h"
#include "graph.h"

class Convert
{
public:
    Convert(const Board *board);
    ~Convert();

    Graph generateGraph();  //tworzy graf na podstawie przekazanej board
    Graph getGraph();   //zwraca graf, ktory tworzymy
private:
    const Board *board;
    Graph graph_;   //tu tworzymy graph
};

#endif // CONVERT_H
