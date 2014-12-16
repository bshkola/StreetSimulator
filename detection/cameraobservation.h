//Author: Wojciech Ceret
//Definition of structure that contains information about camera's remark
//of observed object.
#ifndef CAMERAOBSERVATION_H
#define CAMERAOBSERVATION_H

#include "../common/camera.h"

struct CameraObservation {

    CameraObservation(Camera camera, float object_x, float object_y, float object_distance, float object_azimuth):
        camera(camera), object_x(object_x), object_y(object_y), object_distance(object_distance), object_azimuth(object_azimuth)
        {};

    Camera camera;
    float object_x, object_y, object_distance, object_azimuth;
};

#endif // CAMERAOBSERVATION_H
