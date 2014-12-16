//Author: Andrzej Chmielowski
//Connect to database and put some information to db or get some information from db
#ifndef DATABASE_H
#define DATABASE_H

#include "list"
#include "../../common/camera.h"

using namespace std;
class Database
{
public:
    Database();
    ~Database();

    void addCamerasToDatabase(const list<Camera> cameras);  //add cameras to database, insert information will push suite of camera
    void saveMeasurent(const Camera camera); //save information to database
    void getFromDB(const Camera camera);   //get information from database paramerts - about which camera we would get information
};

#endif // DATABASE_H
