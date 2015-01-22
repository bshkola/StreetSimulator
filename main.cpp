#include "view/mainwindow.h"
#include <QApplication>
#include <memory>

#include "controller/controllerimpl.h"
#include "model/modelimpl.h"
#include <iostream>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

<<<<<<< HEAD
//for test only
#include "model/objectsonmap.h"
#include "model/simulationpreparator.h"
void sokolTest(); //testowanie modelu
//end test
=======
using namespace std;
>>>>>>> master

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

void sokolTest()
{
    ObjectsOnMap objectsOnMap;
    //objectsOnMap.getBoard().size_ = 50;
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {   //add test elements on map
            if( j == 5 || i == 3)
                objectsOnMap.setCellOnField(i, j, true);
            else
                objectsOnMap.setCellOnField(i, j, false);
        }
    }
    //objectsOnMap.addPedestrian(ObjectsOnMap::Cordination(5, 0),
    //                           ObjectsOnMap::Position(4, 5), ObjectsOnMap::Position(8,5));
    //objectsOnMap.addPedestrian(ObjectsOnMap::Cordination(5, 0),
       //                        ObjectsOnMap::Position(4, 5), ObjectsOnMap::Position(25,5));
    SimulationPreparator simulationPreparator(objectsOnMap);
    simulationPreparator.run();
}



