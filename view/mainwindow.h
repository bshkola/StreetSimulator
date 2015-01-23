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

signals:
    void showSimulationWindow();
    void showSimulationBoard(const Board& board);

public slots:
    void updateButtons();
    void updateBoardSize();
    void startSimulation();

protected:

private:
    Ui::MainWindow *ui;
    std::shared_ptr<BoardScene> boardScene;
    QVector<QPushButton*> buttons;
    SimulatorWindow* simulationWindow_;
};

#endif // MAINWINDOW_H
