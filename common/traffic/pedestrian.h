//Author: Wojciech Ceret
//Represent move object on the board
#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include "trafficparticipant.h"
//#include "../../view/items/pede"

struct Pedestrian : public TrafficParticipant {
    Pedestrian(int id, float x, float y, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
        TrafficParticipant(id, x, y, speed, start_point, target_point)
    {}

    ITrafficParticipantItem* createItem(const QRectF& rect) {
//        return new PassengerCarItem(rect);
        return NULL;
    }
};

#endif // PEDESTRIAN_H
