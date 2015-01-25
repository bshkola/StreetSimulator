#include "../view/simulatorwindow.h"
#include <iostream>
#include <QGraphicsPixmapItem>
#include "items/itrafficparticipantitem.h"
#include <QPropertyAnimation>

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
    ui->graphicsView->scene()->clear();
    items.clear();
    engine_->finish();
}

void SimulatorWindow::showBoard(const Board& board) {
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
}

void SimulatorWindow::showTraffic(TrafficParticipants trafficParticipants) {
    for (TrafficParticipant* trafficParticipant : trafficParticipants) {
        ITrafficParticipantItem* item = trafficParticipant->createItem(QRectF(trafficParticipant->x_ * shiftSize_ + shiftSize_ / 4, trafficParticipant->y_ * shiftSize_ + shiftSize_ / 4, shiftSize_ / 2, shiftSize_ / 2));
        item->setId(trafficParticipant->id_);
        ui->graphicsView->scene()->addItem(item);
        items.push_back(item);
    }
}

void SimulatorWindow::updateTraffic(TrafficParticipants trafficParticipants) {
    for (TrafficParticipant* trafficParticipant : trafficParticipants) {
        for (ITrafficParticipantItem* item : items) {
            if (item->getId() == trafficParticipant->id_) {
                QPropertyAnimation* anim = new QPropertyAnimation(item, "pos");
                anim->setDuration(1500);

                anim->setStartValue(QPointF(item->pos()));
                anim->setEndValue(QPointF(item->pos().x() + (trafficParticipant->x_ - trafficParticipant->xBefore_) * shiftSize_,
                                          item->pos().y()+ (trafficParticipant->y_ - trafficParticipant->yBefore_) * shiftSize_));
                anim->start(QAbstractAnimation::DeleteWhenStopped);
                break;
            }
        }
    }
}

