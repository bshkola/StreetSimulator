#include "../../model/database/database.h"

Database::Database()
{

}

void Database::addCamerasToDatabase()
{
    //TODO
}

void Database::saveMeasurent()
{
    databaseConnector_.insertObservations(cameraObservations_);
}

list<CameraObservation*> &Database::getCameraObservation()
{
    return cameraObservations_;
}

Database::~Database()
{

}

