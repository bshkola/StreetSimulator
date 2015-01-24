#ifndef SIMULATORWINDOW_H
#define SIMULATORWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "isimulatorview.h"
#include "ui_simulationwindow.h"
#include "../common/traffic/trafficparticipant.h"
#include "../model/engine/engine.h"

typedef list<TrafficParticipant*> TrafficParticipants;

namespace Ui {
    class SimulationWindow;
}
class Engine;

class SimulatorWindow : public QMainWindow//, public ISimulatorView
{
    Q_OBJECT
public:
    explicit SimulatorWindow(QWidget *parent = NULL);
    virtual ~SimulatorWindow();
    void closeEvent(QCloseEvent* event);
    void initCloseWindowHandler(Engine* engine);

signals:
    void showSignal();
    void showBoardSignal(const Board& board);
    void updateViewSignal(TrafficParticipants trafficParticipants);
    void showTrafficSignal(TrafficParticipants trafficParticipants);

public slots:
    void updateTraffic(TrafficParticipants trafficParticipants);
    void showBoard(const Board& board);
    void showTraffic(TrafficParticipants trafficParticipants);
private:
    Ui::SimulationWindow *ui;
    int shiftSize_;
    Engine* engine_;
};

#endif // SIMULATORWINDOW_H
