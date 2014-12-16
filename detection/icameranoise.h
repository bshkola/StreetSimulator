//Author: Wojciech Ceret
//Interface class for algorithms that makes cameras' observations slightly inccurate.
#ifndef ICAMERANOISE_H
#define ICAMERANOISE_H

#include <utility>

class ICameraNoise {
public:
    ICameraNoise() {};
    virtual ~ICameraNoise() {};

    //arguments: (X, Y, distance, pecentage)
    // X, Y - actual coordinates of TrafficParticipant
    // distance - distance between Camera and TrafficParticipant
    // pecentage - maximal dislocation of TrafficParticipant on X and Y axis (percents of distance)
    //returns: noised location of TrafficParticipant
    virtual std::pair<float, float> introduceNoise(float, float, float, int) = 0;
};

#endif // ICAMERANOISE_H
