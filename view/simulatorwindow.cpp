#include "../view/simulatorwindow.h"
#include <iostream>
#include <QGraphicsPixmapItem>
#include "items/passengercaritem.h"

SimulatorWindow::SimulatorWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SimulationWindow) {
    ui->setupUi(this);
    setWindowModality(Qt::WindowModal);

    qRegisterMetaType<TrafficParticipants>("TrafficParticipants");

    connect(this, SIGNAL(showSignal()), this, SLOT(show()));
    connect(this, SIGNAL(showBoardSignal(Board)), this, SLOT(showBoard(Board)));
    connect(this, SIGNAL(updateViewSignal(TrafficParticipants)), this, SLOT(updateTraffic(TrafficParticipants)));
    connect(this, SIGNAL(showTrafficSignal(TrafficParticipants)), this, SLOT(showTraffic(TrafficParticipants)));
}

SimulatorWindow::~SimulatorWindow() {
    std::cout << "~SimulatorWindow()" << std::endl;
}

void SimulatorWindow::initCloseWindowHandler(Engine* engine) {
    engine_ = engine;
}

void SimulatorWindow::closeEvent(QCloseEvent* event) {
    QMainWindow::closeEvent(event);
    engine_->finish();
}

void SimulatorWindow::showBoard(const Board& board) {
    std::cout << "SHOWING THE BOARD >>>>> " << board.size_ << std::endl;
    for (int i = 0; i < board.size_; i++) {
        for (int j = 0; j < board.size_; j++) {
            if (board.boardMap_[i][j]) {
                std::cout << "x";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    QGraphicsScene* scene = new QGraphicsScene(0, 0, 600, 600);
    ui->graphicsView->setScene(scene);

    shiftSize_ = std::min(width(), height()) / board.size_;

    QPen blackPen(Qt::black);
    QBrush grayBrush(Qt::gray);
    QBrush greenBrush(Qt::green);

    for (int i = 0; i < board.size_; i++) {
        for (int j = 0; j < board.size_; j++) {
            QRectF rect(i * shiftSize_, j * shiftSize_, shiftSize_, shiftSize_);
            if (board.boardMap_[i][j]) {
                ui->graphicsView->scene()->addRect(rect, blackPen, grayBrush);
            } else {
                ui->graphicsView->scene()->addRect(rect, blackPen, greenBrush);
            }
        }
    }

    /*PassengerCarItem* item = new PassengerCarItem(QRectF(2 * shiftSize_, 2 * shiftSize_, shiftSize_ / 2, shiftSize_ / 2));
    ui->graphicsView->scene()->addItem(item);
    std::vector<TrafficParticipant*> participants;
    //participants.push_back(new TrafficParticipant(2, 5, 1, Position(0, 0)), Position(0, 0))});
    */
}

void SimulatorWindow::showTraffic(TrafficParticipants trafficParticipants) {
    for (TrafficParticipant* trafficParticipant : trafficParticipants) {
        PassengerCarItem* item = new PassengerCarItem(QRectF(trafficParticipant->x_ * shiftSize_, trafficParticipant->y_ * shiftSize_, shiftSize_ / 2, shiftSize_ / 2));
        ui->graphicsView->scene()->addItem(item);
    }
    std::cout << "elements added" << std::endl;
}

void SimulatorWindow::updateTraffic(TrafficParticipants trafficParticipants) {
    std::cout << "updating" << std::endl;

    //ui->graphicsView->scene()->clear();
    for (TrafficParticipant* trafficParticipant : trafficParticipants) {
        //std::cout << "Part: " << trafficParticipant->x_ << " " << trafficParticipant->y_ << std::endl;
        PassengerCarItem* item = new PassengerCarItem(QRectF(trafficParticipant->x_ * shiftSize_, trafficParticipant->y_ * shiftSize_, shiftSize_ / 2, shiftSize_ / 2));
        ui->graphicsView->scene()->addItem(item);
    }


}
