#include "view/mainwindow.h"
#include <QApplication>
#include <memory>

#include "controller/controllerimpl.h"
#include "model/modelimpl.h"
#include <iostream>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL)); //initialize random seed

    QApplication a(argc, argv);
    IView* window = new MainWindow();
    window->show();

    shared_ptr<IModel> model = make_shared<ModelImpl>();
    shared_ptr<IController> controller = make_shared<ControllerImpl>(model, window);
    QtConcurrent::run(controller.get(), &IController::start);
    cout << "models >> " << model.use_count() << endl;
    int result = a.exec();
    //delete window;
    return result;
}



