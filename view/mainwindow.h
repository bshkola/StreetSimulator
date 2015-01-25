//Author: Bogdan Shkola
//Representing main window of application.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include "iview.h"
#include "boardscene.h"
#include "simulatorwindow.h"

namespace Ui {
    class MainWindow;
}
class BoardScene;

class MainWindow : public QMainWindow, public IView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);
    void showBoard(const Board& board);
    void show();
    void setCameraOptions(const CameraOptions& cameraOptions);

signals:
    void showSimulationWindow();
    void showMessageSignal(std::string message);

public slots:
    void updateBoardSize();
    void startSimulation();
    void changeCameraOptionsPressed();
    void showMessage(std::string message);

private:
    Ui::MainWindow *ui;
    SimulatorWindow* simulationWindow_;
    std::shared_ptr<BoardScene> boardScene;
};

#endif // MAINWINDOW_H
