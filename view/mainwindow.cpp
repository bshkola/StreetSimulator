#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "QMessageBox"
#include "boardscene.h"
#include "../controller/blockingqueue.h"
#include "../common/events/windowclosedevent.h"
#include "../common/events/boardsizechangedevent.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), IView(), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    boardScene = new Ui::BoardScene();
    ui->graphicsView->setScene(boardScene);
    this->setWindowTitle("Editor");
    this->showMaximized();

    boardScene->updateBoardSize(ui->boardSizeSpinBox->value());

    // initialize signals-slots
    buttons.append(ui->streetButton);
    buttons.append(ui->removeStreetButton);
    buttons.append(ui->movableObjectButton);
    buttons.append(ui->cameraButton);

    connect(ui->sizeButton, SIGNAL(clicked()), this, SLOT(updateButtons()));
    connect(ui->sizeButton, SIGNAL(pressed()), this, SLOT(updateBoardSize()));

    connect(ui->streetButton, SIGNAL(pressed()), this, SLOT(updateButtons()));
    connect(ui->removeStreetButton, SIGNAL(pressed()), this, SLOT(updateButtons()));
    connect(ui->movableObjectButton, SIGNAL(pressed()), this, SLOT(updateButtons()));
    connect(ui->cameraButton, SIGNAL(pressed()), this, SLOT(updateButtons()));
}

MainWindow::~MainWindow()
{
    delete ui;
    std::cout << "~MainWindow" << std::endl;
}

void MainWindow::show()
{
    QMainWindow::show();
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

void MainWindow::updateButtons() {
    for (QPushButton* button : buttons) {
        button->setChecked(false);
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
