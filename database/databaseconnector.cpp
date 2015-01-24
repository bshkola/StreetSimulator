//Author: Wojciech Ceret
//Implementation of methods for connecting to database
//and inserting observations into it.
/*
#include "databaseconnector.h"

//    Example of possible message:
//    "Camera number camera_number_ [x_, y_, azimuth_, angle_, range_]
//     spotted object at [object_x, object_y, object_distance, object_azimuth]."

//    MySQL table columns:
//    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY
//    cam_nr INT
//    cam_pos_x DOUBLE
//    cam_pos_y DOUBLE
//    cam_azimuth DOUBLE
//    cam_angle DOUBLE
//    cam_range DOUBLE
//    obj_pos_x DOUBLE
//    obj_pos_y DOUBLE
//    obj_distance DOUBLE
//    obj_azimuth DOUBLE

DatabaseConnector::DatabaseConnector()
{
    //opening configuration file for reading
    std::ifstream config_file;
    config_file.open ("config");

    //checking if stream opened succesfully
    if (config_file.is_open())
    {
        //reading configuration from a stream
        getline (config_file, db_host_);
        getline (config_file, db_user_);
        getline (config_file, db_passwd_);
        getline (config_file, db_dbname_);
        getline (config_file, db_table_);
    } else {
        //default configuration
        db_host_ = "tcp://127.0.0.1:3306";
        db_user_ = "root";
        db_passwd_ = "toor";
        db_dbname_ = "StreetSimulator";
        db_table_ = "observations";
    }

    //closing stream from a file
    config_file.close();

    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        //Create a connection
        driver = get_driver_instance();
        con = driver->connect(db_host_, db_user_, db_passwd_);
        //Connect to the MySQL database
        con->setSchema(db_dbname_);

        //create table
        stmt = con->createStatement();
        stmt->execute("CREATE TABLE IF NOT EXISTS " + db_table_ +
                      " ( " +
                          "id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, " +
                          "cam_nr INT, " +
                          "cam_pos_x DOUBLE, " +
                          "cam_pos_y DOUBLE, " +
                          "cam_azimuth DOUBLE, " +
                          "cam_angle DOUBLE, " +
                          "cam_range DOUBLE, " +
                          "obj_pos_x DOUBLE, " +
                          "obj_pos_y DOUBLE, " +
                          "obj_distance DOUBLE, " +
                          "obj_azimuth DOUBLE " +
                      " );"
                     );
        delete stmt;

        //disconnect from database
        delete con;
    } catch (sql::SQLException &e) {
        std::cout << "# Error in database connection in DatabaseConnector::DatabaseConnector()" << std::endl;
    }
}

void DatabaseConnector::insertObservations(const std::list<CameraObservation*>& observation_list)
{
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::PreparedStatement *pstmt;

        //Create a connection
        driver = get_driver_instance();
        con = driver->connect(db_host_, db_user_, db_passwd_);
        //Connect to the MySQL database
        con->setSchema(db_dbname_);

        //begin transaction
        stmt = con->createStatement();
        stmt->execute("START TRANSACTION;");

        //prepare statement
        // '?' is the supported placeholder syntax
        pstmt = con->prepareStatement("INSERT INTO " + db_table_ +
                                      " ( " +
                                          "cam_nr, " +
                                          "cam_pos_x, " +
                                          "cam_pos_y, " +
                                          "cam_azimuth, " +
                                          "cam_angle, " +
                                          "cam_range, " +
                                          "obj_pos_x, " +
                                          "obj_pos_y, " +
                                          "obj_distance, " +
                                          "obj_azimuth " +
                                      ") " +
                                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);"
                                     );

        //for every observation in given list
        for(std::list<CameraObservation*>::const_iterator obs_it = observation_list.cbegin();
            obs_it != observation_list.cend();
            ++obs_it)
        {
            //extract data from list and set prepared statement's fields
            pstmt->setInt(1, ((*obs_it)->camera).number_);
            pstmt->setDouble(2, ((*obs_it)->camera).x_);
            pstmt->setDouble(3, ((*obs_it)->camera).y_);
            pstmt->setDouble(4, ((*obs_it)->camera).azimuth_);
            pstmt->setDouble(5, ((*obs_it)->camera).angle_);
            pstmt->setDouble(6, ((*obs_it)->camera).range_);
            pstmt->setDouble(7, (*obs_it)->object_x);
            pstmt->setDouble(8, (*obs_it)->object_y);
            pstmt->setDouble(9, (*obs_it)->object_distance);
            pstmt->setDouble(10, (*obs_it)->object_azimuth);
            //insert data into database's table
            pstmt->executeUpdate();
        }
        delete pstmt;

        //commit transaction
        stmt->execute("COMMIT;");
        delete stmt;

        //disconnect from database
        delete con;
    } catch (sql::SQLException &e) {
        std::cout << "# Error in database connection in DatabaseConnector::insertObservations(const std::list<CameraObservation*>&)" << std::endl;
    }
}
*/
