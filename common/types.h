#ifndef TYPES_H
#define TYPES_H

#include <utility>

typedef std::pair<float, float> Coordinates;
typedef std::pair<int, int> Position;

enum ObjectType {
    DESTINATION = -1,
    PEDESTRIAN = 0,
    CAR = 1,
    TRUCK = 2,
    CAMERA = 3,
};

#endif // TYPES_H
