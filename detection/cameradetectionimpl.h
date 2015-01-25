//Author: Wojciech Ceret
//Definition of class with implementation of algorithm that determines detection
//of objects by cameras.
#ifndef CAMERADETECTIONIMPL_H
#define CAMERADETECTIONIMPL_H

#include "icameradetection.h"

class CameraDetectionImpl : public ICameraDetection {
public:
    CameraDetectionImpl(ICameraNoise *NoiseGenerator): ICameraDetection(NoiseGenerator), NoiseGenerator(NoiseGenerator) {}
    virtual ~CameraDetectionImpl() { delete NoiseGenerator; }
    
    ICameraNoise *NoiseGenerator;
    
    virtual void calculate(const std::list<Camera*>&,
                            const std::list<TrafficParticipant*>&,
                            std::list<CameraObservation*>&,
                            const int);

    float pair_distance(const std::pair<float, float>, const std::pair<float, float>);
    float distance(const float, const float);
    float azimuth(const std::pair<float, float>, const std::pair<float, float>);
    bool withinTheAngle(float, float, float);
    void normalizeAzimuth(float&);
    void normalizeAngle(float&);
};

#endif // CAMERADETECTIONIMPL_H
