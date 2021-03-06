//Author: Wojciech Ceret
//Represent move object on the board
#ifndef VEHICLE_H
#define VEHICLE_H

#include "trafficparticipant.h"

struct Vehicle : public TrafficParticipant {
protected:
    Vehicle(int id, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
        TrafficParticipant(id, speed, start_point, target_point) {
    }
};

#endif // VEHICLE_H
