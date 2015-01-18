//Author: Wojciech Ceret
//Definition of class with implementation of algorithm that determines detection
//of objects by cameras.
#ifndef CAMERADETECTIONIMPL_H
#define CAMERADETECTIONIMPL_H

#include "icameradetection.h"

class CameraDetectionImpl : public ICameraDetection {
public:
    CameraDetectionImpl(ICameraNoise *NoiseGenerator): ICameraDetection(NoiseGenerator), NoiseGenerator(NoiseGenerator) {};
    virtual ~CameraDetectionImpl() { delete NoiseGenerator; };
    
    ICameraNoise *NoiseGenerator;
    
    virtual void calculate( const std::list<Camera*>&,
                            const std::list<TrafficParticipant*>&,
                            std::list<CameraObservation*>&);

    float distance(const std::pair<float, float>, const std::pair<float, float>);
    float azimuth(const std::pair<float, float>, const std::pair<float, float>);
    bool withinTheAngle(float, float, float);
};

#endif // CAMERADETECTIONIMPL_H
