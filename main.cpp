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
    IView* window = new MainWindow();
    window->show();

    Model::IModel* model = new Model::ModelImpl();
    IController* controller = new ControllerImpl(model, window);

    QFuture<void> controllerThread = QtConcurrent::run(controller, &IController::start);
    return a.exec();
}
