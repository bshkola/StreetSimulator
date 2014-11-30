#include "view/mainwindow.h"
#include <QApplication>

#include "controller/controllerimpl.h"
#include "model/modelimpl.h"
#include <iostream>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Model::IModel* m = new Model::ModelImpl;
    Controller::ControllerImpl* c = new Controller::ControllerImpl;

    QFuture<void> controllerThread = QtConcurrent::run(c, &Controller::ControllerImpl::start);

    return a.exec();
}
