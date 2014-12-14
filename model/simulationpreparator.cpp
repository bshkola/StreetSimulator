#include "model/simulationpreparator.h"

SimulationPreparator::SimulationPreparator(const Board &board): convert(board)
{
    this->dijkstra = new Dijkstra(this->convert.generateGraph());   //generujemy graph i tworzymy dijkstre
}


void SimulationPreparator::run()
{   //oblicza droge dla kazdego obiektu i zapijuhe ja do tablicy
    //TODO
}

SimulationPreparator::~SimulationPreparator()
{
    //niszczymy obiekty z dynamiczna alkacja pamieci w konstruktorze
    delete this->dijkstra;
}

