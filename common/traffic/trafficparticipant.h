//Author: Wojciech Ceret
//Represent move object on the board
#ifndef TRAFFICPARTICIPANT_H
#define TRAFFICPARTICIPANT_H

#include<utility>

struct TrafficParticipant {
    float x, y;     //coordinates of object placed on the map
    float speed;    //speed of moving object
    std::pair<int, int> start_point, target_point;  //begin & end of path
protected:
    TrafficParticipant(float x, float y, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
        x(x), y(y), speed(speed), start_point(start_point), target_point(target_point)
    {};
};

#endif // TRAFFICPARTICIPANT_H
