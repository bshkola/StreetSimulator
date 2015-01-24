//Author: Wojciech Ceret
//Object providing methods for connecting to database
//and inserting observations into it.
/*
#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

//Standard C++ includes
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

//Header files for database connections
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

//Headers from project
#include "../detection/cameraobservation.h"

class DatabaseConnector
{
    std::string db_host_, db_user_, db_passwd_, db_dbname_, db_table_;

public:
    DatabaseConnector();
    void insertObservations(const std::list<CameraObservation*>&);
};

#endif // DATABASECONNECTOR_H
*/
