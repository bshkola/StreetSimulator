//Author: Wojciech Ceret
//Definition of class with implementation of algorithm that determines detection
//of objects by cameras.
#ifndef CAMERADETECTIONIMPL_H
#define CAMERADETECTIONIMPL_H

#include "icameradetection.h"

class CameraDetectionImpl : ICameraDetection {
public:
    CameraDetectionImpl();
    virtual ~CameraDetectionImpl();
    virtual void calculate( const std::list<Camera*>&,
                            const std::list<TrafficParticipant*>&,
                            std::list<CameraObservation*>&);
};

#endif // CAMERADETECTIONIMPL_H
