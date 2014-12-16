//Author: Wojciech Ceret
//Definition of class with implementation of algorithm that makes cameras'
//observations slightly inccurate.
#ifndef CAMERANOISEIMPL_H
#define CAMERANOISEIMPL_H

#include "icameranoise.h"

class CameraNoiseImpl : ICameraNoise {
public:
    CameraNoiseImpl();
    virtual ~CameraNoiseImpl();
    virtual std::pair<float, float> introduceNoise(float, float, float, int);
};

#endif // CAMERANOISEIMPL_H
