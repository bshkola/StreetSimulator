//Author: Wojciech Ceret
//Represent object camera on the board
#ifndef CAMERA_H
#define CAMERA_H

struct Camera {
    Camera(int id, float x, float y, float azimuth, float angle, float range) :
        id_(id), x_(x), y_(y), azimuth_(azimuth), angle_(angle), range_(range)
    {
    }

    const int id_;
    float x_, y_;                     //coordinates of camera placed on the map
    float azimuth_, angle_, range_;   //atributes of camera
    int number_;                      //unique number of camera
};

#endif // CAMERA_H
