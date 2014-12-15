//Author: Wojciech Ceret
//Definition of structure that contains information about camera's remark
//of observed object.
#ifndef CAMERAOBSERVATION_H
#define CAMERAOBSERVATION_H

#include "../common/camera.h"
#include "../common/traffic/trafficparticipant.h"

struct CameraObservation {
    Camera camera;
    float object_x, object_y, object_distance, object_azimuth;
};

#endif // CAMERAOBSERVATION_H
