//Author: Wojciech Ceret
//Represent move object on the board
#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include "trafficparticipant.h"

struct Pedestrian : public TrafficParticipant {
    Pedestrian(float x, float y, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
        TrafficParticipant(x, y, speed, start_point, target_point)
    {}
};

#endif // PEDESTRIAN_H
