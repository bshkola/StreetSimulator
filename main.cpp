#include "view/mainwindow.h"
#include <QApplication>

#include "controller/controllerimpl.h"
#include "model/modelimpl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Controller::IController* c = new Controller::ControllerImpl;
    Model::IModel* m = new Model::ModelImpl;

    return a.exec();
}
