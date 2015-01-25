//Author: Bogdan Shkola
//Representing main window of application.
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    //Handles resizing od the window
    void resizeEvent(QResizeEvent *event);
    //handles closing the window
    void closeEvent(QCloseEvent *event);
    //Shows the editor's board scene
    void showBoard(const Board& board);
    //Shows the window
    void show();
    //Set camera options (characreristic) in the camera form
    void setCameraOptions(const CameraOptions& cameraOptions);

signals:
    //Signal for getting simulation window
    void showSimulationWindow();
    //Signal for displaying the message
    void showMessageSignal(std::string message);

public slots:
    //updates board size when changing it
    void updateBoardSize();
    //Starts simulation when clicking the button
    void startSimulation();
    //Change camera options in the model
    void changeCameraOptionsPressed();
    //Shows message on the window
    void showMessage(std::string message);

private:
    Ui::MainWindow *ui;
    //Window of the simulation
    SimulatorWindow* simulationWindow_;
    //Editor's board graphics scene
    std::shared_ptr<BoardScene> boardScene_;
};

#endif // MAINWINDOW_H
