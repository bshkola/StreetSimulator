#ifndef SIMULATORWINDOW_H
#define SIMULATORWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "isimulatorview.h"
#include "ui_simulationwindow.h"
#include "../common/traffic/trafficparticipant.h"

namespace Ui {
    class SimulationWindow;
}

class SimulatorWindow : public QMainWindow//, public ISimulatorView
{
    Q_OBJECT
public:
    explicit SimulatorWindow(QWidget *parent = NULL);
    virtual ~SimulatorWindow();

public slots:
    void showBoard(const Board& board);
    void showObjectsOnMap(std::vector<TrafficParticipant*> trafficParticipants);
private:
    Ui::SimulationWindow *ui;
    int shiftSize_ ;
};

#endif // SIMULATORWINDOW_H
