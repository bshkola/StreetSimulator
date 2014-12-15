//Author: Wojciech Ceret
//Interface class for algorithms that determines detection of objects by cameras.
#ifndef ICAMERADETECTION_H
#define ICAMERADETECTION_H

#include <list>
#include "../common/camera.h"
#include "../common/traffic/trafficparticipant.h"
#include "cameraobservation.h"

class ICameraDetection {
public:
    ICameraDetection() {};
    virtual ~ICameraDetection() {};

    //arguments: (camera_list, tp_list, observation_list)
    // camera_list - reference to std::list of pointers to Camera class' objects
    //  containing information about all working cameras in simulation.
    // tp_list - reference to std::list of pointers to TrafficParticipant class'
    //  objects containing information about snapshoted positions of moving
    //  objects in simulation.
    // observation_list - reference to empty std::list of pointers to
    //  CameraObservation class' objects - method dynamicly creates objects and
    //  puts pointers on given list.
    //returns: nothing
    virtual void calculate( const std::list<Camera*>&,
                            const std::list<TrafficParticipant*>&,
                            std::list<CameraObservation*>&) = 0;
};

#endif // ICAMERADETECTION_H
