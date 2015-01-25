//Author: Bogdan Shkola
//Implementation of MainWindow class
#include "mainwindow.h"

#include <QMessageBox>
#include "ui_mainwindow.h"
#include "../controller/blockingqueue.h"
#include "../common/events/windowclosedevent.h"
#include "../common/events/boardsizechangedevent.h"
#include "../common/events/startsimulationevent.h"
#include "../common/events/cameraoptionschangedevent.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), IView(), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    boardScene_ = std::make_shared<BoardScene>();
    ui->graphicsView->setScene(boardScene_.get());
    this->setWindowTitle("Editor");
    this->showMaximized();

    simulationWindow_ = new SimulatorWindow(this);

    // initialize signals-slots
    qRegisterMetaType<Board>("Board");
    qRegisterMetaType<std::string>("std::string");
    connect(ui->sizeButton, SIGNAL(pressed()), this, SLOT(updateBoardSize()));
    connect(ui->cameraButton, SIGNAL(pressed()), this, SLOT(changeCameraOptionsPressed()));
    connect(ui->simmulationButton, SIGNAL(pressed()), this, SLOT(startSimulation()));
    connect(this, SIGNAL(showMessageSignal(std::string)), this, SLOT(showMessage(std::string)));

    connect(this, SIGNAL(showSimulationWindow()), simulationWindow_, SLOT(show()));
}

MainWindow::~MainWindow() {
    delete ui;
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
    int cameraId = boardScene_->getActiveCameraId();
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
        boardScene_->updateBoardSize(ui->boardSizeSpinBox->value());
        BlockingEventQueue::getInstance().push(new BoardSizeChangedEvent(ui->boardSizeSpinBox->value()));
    }
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);

    boardScene_->setSceneRect(boardScene_->sceneRect());
    ui->graphicsView->fitInView(boardScene_->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
    BlockingEventQueue::getInstance().push(new WindowClosedEvent());
}

void MainWindow::showBoard(const Board& board) {
    ui->boardSizeSpinBox->setValue(board.size_);
    boardScene_->updateBoardSize(board.size_);
}

void MainWindow::showMessage(std::string message) {
    QMessageBox messageBox;
    messageBox.setText(message.c_str());
    messageBox.exec();
}
