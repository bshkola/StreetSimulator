#ifndef DATABASE_H
#define DATABASE_H

#include "../../common/camera.h"

class Database
{
public:
    Database();
    ~Database();

    void saveToDB(const Camera camera); //save information to database
};

#endif // DATABASE_H
