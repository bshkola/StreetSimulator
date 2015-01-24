//Author: Bogdan Shkola
//Representing main window of application.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include "iview.h"
#include "boardscene.h"


namespace Ui {
    class MainWindow;
}
class BoardScene;

class MainWindow : public QMainWindow, public IView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);
    void showBoard(const Board& board);
    void show();
    void setCameraOptions(const CameraOptions& cameraOptions);
    virtual ~MainWindow();

public slots:
    void updateBoardSize();
    void startSimulation();
    void changeCameraOptionsPressed();

protected:

private:
    Ui::MainWindow *ui;
    BoardScene* boardScene;
};

#endif // MAINWINDOW_H
