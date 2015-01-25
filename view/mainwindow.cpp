#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "QMessageBox"
#include "../controller/blockingqueue.h"
#include "../common/events/windowclosedevent.h"
#include "../common/events/boardsizechangedevent.h"
#include "../common/events/startsimulationevent.h"
#include "../view/simulatorwindow.h"
#include "../common/events/cameraoptionschangedevent.h"
#include "../common/cameraoptions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), IView(), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    boardScene = std::make_shared<BoardScene>();
    ui->graphicsView->setScene(boardScene.get());
    this->setWindowTitle("Editor");
    this->showMaximized();

    simulationWindow_ = new SimulatorWindow(this);

    // initialize signals-slots
    connect(ui->sizeButton, SIGNAL(pressed()), this, SLOT(updateBoardSize()));
    connect(ui->cameraButton, SIGNAL(pressed()), this, SLOT(changeCameraOptionsPressed()));
    connect(ui->simmulationButton, SIGNAL(pressed()), this, SLOT(startSimulation()));

    qRegisterMetaType<Board>("Board");
    connect(this, SIGNAL(showSimulationWindow()), simulationWindow_, SLOT(show()));
    connect(this, SIGNAL(showSimulationBoard(Board)), simulationWindow_, SLOT(showBoard(Board)));
}

MainWindow::~MainWindow()
{
    delete ui;
    std::cout << "~MainWindow" << std::endl;
}

void MainWindow::show() {
    QMainWindow::show();
}

void MainWindow::setCameraOptions(const CameraOptions& cameraOptions) {
    ui->cameraAngleSpinBox->setValue(cameraOptions.getAngle());
    ui->cameraDirectionSpinBox->setValue(cameraOptions.getDirection());
    ui->cameraRangeSpinBox->setValue(cameraOptions.getRange());
}

void MainWindow::changeCameraOptionsPressed() {
    int cameraId = boardScene->getActiveCameraId();
    if (cameraId != -1) {
        BlockingEventQueue::getInstance().push(
                    new CameraOptionsChangedEvent(cameraId, CameraOptions(ui->cameraAngleSpinBox->value(),
                          ui->cameraDirectionSpinBox->value(), ui->cameraRangeSpinBox->value())));
    }
}

void MainWindow::startSimulation() {
    BlockingEventQueue::getInstance().push(new StartSimulationEvent(simulationWindow_));
}

void MainWindow::updateBoardSize() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning", "Do you want to change the size of the board? All information will be lost",
                                QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        boardScene->updateBoardSize(ui->boardSizeSpinBox->value());
        BlockingEventQueue::getInstance().push(new BoardSizeChangedEvent(ui->boardSizeSpinBox->value()));
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    boardScene->setSceneRect(boardScene->sceneRect());
    ui->graphicsView->fitInView(boardScene->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
    BlockingEventQueue::getInstance().push(new WindowClosedEvent());
}

void MainWindow::showBoard(const Board& board) {
    std::cout << "showing Board" << std::endl;
    ui->boardSizeSpinBox->setValue(8);
    boardScene->updateBoardSize(8);
}
