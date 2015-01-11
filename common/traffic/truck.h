//Author: Wojciech Ceret
//Represent move object on the board
#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

struct Truck : public Vehicle {
    Truck(float x, float y, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
       Vehicle(x, y, speed, start_point, target_point)
    {}
};

#endif // TRUCK_H
