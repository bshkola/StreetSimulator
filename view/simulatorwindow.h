//Author: Bogdan Shkola
//Simulator window, which contains simulator graphics scene
#ifndef SIMULATORWINDOW_H
#define SIMULATORWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ui_simulationwindow.h"
#include "../common/traffic/trafficparticipant.h"
#include "../model/engine/engine.h"

typedef list<TrafficParticipant*> TrafficParticipants;

namespace Ui {
    class SimulationWindow;
}
class Engine;

class SimulatorWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SimulatorWindow(QWidget *parent = NULL);
    virtual ~SimulatorWindow();
    //Executed when closing the window. Ends simulation loop
    void closeEvent(QCloseEvent* event);
    //Sets the engine of the simulation.
    void setEngine(Engine* engine);

signals:
    //Signal displaying the simulation window
    void showSignal();
    //Signal for displaying board scene of the simulation
    void showBoardSignal(const Board& board);
    //Signal updating the traffic in the simulation
    void updateViewSignal(TrafficParticipants trafficParticipants);
    //Signal creating traffic objects before simulation
    void showTrafficSignal(TrafficParticipants trafficParticipants);

public slots:
    //Updates traffic position
    void updateTraffic(TrafficParticipants trafficParticipants);
    //Displays the board scene
    void showBoard(const Board& board);
    //Creates traffic objects before simulation started
    void showTraffic(TrafficParticipants trafficParticipants);
private:    
    Ui::SimulationWindow *ui;
    //Size of the cell
    int shiftSize_;
    //Engine of simulation
    Engine* engine_;
    //Traffic objects in the simulation
    std::vector<ITrafficParticipantItem*> items;
};

#endif // SIMULATORWINDOW_H
