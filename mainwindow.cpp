#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttons.append(ui->streetButton);
    buttons.append(ui->removeStreetButton);
    buttons.append(ui->movableObjectButton);
    buttons.append(ui->cameraButton);

    connect(ui->sizeButton, SIGNAL(clicked()), this, SLOT(updateButtons()));

    connect(ui->streetButton, SIGNAL(pressed()), this, SLOT(updateButtons()));
    connect(ui->removeStreetButton, SIGNAL(pressed()), this, SLOT(updateButtons()));
    connect(ui->movableObjectButton, SIGNAL(pressed()), this, SLOT(updateButtons()));
    connect(ui->cameraButton, SIGNAL(pressed()), this, SLOT(updateButtons()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateButtons() {
    for (QPushButton* button : buttons) {
        button->setChecked(false);
    }
}
