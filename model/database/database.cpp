#include "../../model/database/database.h"

Database::Database(const int size): size_(size)
{

}

void Database::saveMeasurent()
{
    databaseConnector_.insertObservations(cameraObservations_, size_);
    for(CameraObservation* el: cameraObservations_)
        delete el;
    cameraObservations_.clear();
}

list<CameraObservation*> &Database::getCameraObservation()
{
    return cameraObservations_;
}

Database::~Database()
{

}

