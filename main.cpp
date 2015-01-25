//Author: Bogdan Shkola
//Main class

#include <QApplication>
#include <memory>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include "view/mainwindow.h"
#include "model/modelimpl.h"
#include "controller/controllerimpl.h"

int main(int argc, char *argv[])
{
    srand(time(NULL)); //initialize random seed

    QApplication a(argc, argv);
    IView* window = new MainWindow();
    shared_ptr<IModel> model = make_shared<ModelImpl>();
    shared_ptr<IController> controller = make_shared<ControllerImpl>(model, window);
    QtConcurrent::run(controller.get(), &IController::start);
    return a.exec();
}
