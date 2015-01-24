//Author: Wojciech Ceret
//Represent move object on the board
#ifndef TRAFFICPARTICIPANT_H
#define TRAFFICPARTICIPANT_H

#include <utility>
#include <deque>
#include "../../common/types.h"

struct TrafficParticipant {
    const int id_;
    int xBefore_, yBefore_;
    int x_, y_;     //coordinates of object placed on the map
    float speed_;    //speed of moving object
    Position startPoint_, targetPoint_;  //begin & end of path
    std::deque<std::pair<int, int>> way; //way where is ride object
protected:
    TrafficParticipant(int id, int x, int y, float speed, Position startPoint, Position targetPoint):
        id_(id), x_(x), y_(y), speed_(speed), startPoint_(startPoint), targetPoint_(targetPoint)
    {}
};

#endif // TRAFFICPARTICIPANT_H
