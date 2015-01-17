//Author: Wojciech Ceret
//Represent move object on the board
#ifndef TRAFFICPARTICIPANT_H
#define TRAFFICPARTICIPANT_H

#include<utility>

struct TrafficParticipant {
    int x_, y_;     //coordinates of object placed on the map
    float speed;    //speed of moving object
    std::pair<int, int> start_point, target_point;  //begin & end of path
protected:
    TrafficParticipant(int x, int y, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
        x_(x), y_(y), speed(speed), start_point(start_point), target_point(target_point)
    {};
};

#endif // TRAFFICPARTICIPANT_H
