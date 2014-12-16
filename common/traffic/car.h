//Author: Wojciech Ceret
//Represent move object on the board
#ifndef CAR_H
#define CAR_H

#include "truck.h"

struct Car : Vehicle {
    Car(float x, float y, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
       Vehicle(x, y, speed, start_point, target_point)
    {};
};

#endif // CAR_H
