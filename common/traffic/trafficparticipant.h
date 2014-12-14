#ifndef TRAFFICPARTICIPANT_H
#define TRAFFICPARTICIPANT_H

#include<utility>

struct TrafficParticipant {
    float x, y;     //coordinates of object placed on the map
    float speed;    //speed of moving object
    std::pair<int, int> start_point, target_point;  //begin & end of path
};

#endif // TRAFFICPARTICIPANT_H
