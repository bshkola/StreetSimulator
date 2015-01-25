//Author: Wojciech Ceret
//Implementation of algorithm that makes cameras' observations slightly inccurate.
#include <cstdlib>
#include <ctime>
#include "cameranoiseimpl.h"

#define MAX_PERCENTAGE 10

CameraNoiseImpl::CameraNoiseImpl() {};

CameraNoiseImpl::~CameraNoiseImpl() {};

std::pair<float, float> CameraNoiseImpl::introduceNoise(float x, float y, float distance, int percentage = MAX_PERCENTAGE){
    //constrain max noise
    int used_percentage = 
        (0 <= percentage && percentage < MAX_PERCENTAGE) ? percentage : MAX_PERCENTAGE;

    int sign = (rand() % 2) ? 1 : -1;
    float new_x = x + sign*(used_percentage/100)*distance*(((rand() % 100)+1)/100);
    sign = (rand() % 2) ? 1 : -1;
    float new_y = y + sign*(used_percentage/100)*distance*(((rand() % 100)+1)/100);

    return std::pair<float, float>(new_x, new_y);
};
