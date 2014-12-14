#ifndef VEHICLE_H
#define VEHICLE_H

#include "truck.h"

struct Vehicle : TrafficParticipant {
    Vehicle(float x, float y, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
        TrafficParticipant(x, y, speed, start_point, target_point)
    {}
};

#endif // VEHICLE_H
