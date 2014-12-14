#ifndef SIMULATIONPREPARATOR_H
#define SIMULATIONPREPARATOR_H

#include "../common/board.h"
#include "convert.h"
#include "dijkstra.h"

class SimulationPreparator
{
public:
    SimulationPreparator(const Board &borad);    //(board, lista_obiektow);
    ~SimulationPreparator();

    void run(); //uruchamia, oblicza droge dla kazdego z obiektow
private:
    Convert convert;    //obiekt ktory konwertuje z board do grafu
    Dijkstra *dijkstra; //obiekt ktory liczy droge dla pojedynczego obiektu
};

#endif // SIMULATIONPREPARATOR_H
