//Author: Andrzej Chmielowski
//Connect to database and put some information to db or get some information from db
#ifndef DATABASE_H
#define DATABASE_H

#include "../../database/databaseconnector.h"
#include "list"
#include "../../detection/cameraobservation.h"

using namespace std;
class Database
{
public:
    Database();
    ~Database();

    void addCamerasToDatabase();  //add cameras to database, insert information will push suite of camera
    void saveMeasurent(); //save information to database
    list<CameraObservation*> &getCameraObservation();   //get information from database paramerts - about which camera we would get information
private:
    list<CameraObservation*> cameraObservations_; //list of result measured by camera
    DatabaseConnector databaseConnector_; //connect to database
};

#endif // DATABASE_H
