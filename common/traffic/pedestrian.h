//Author: Wojciech Ceret
//Represent move object on the board
#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H

#include "trafficparticipant.h"
#include "../../view/items/pedestrianitem.h"

struct Pedestrian : public TrafficParticipant {
    Pedestrian(int id, float speed, std::pair<int, int> start_point, std::pair<int, int> target_point):
        TrafficParticipant(id, speed, start_point, target_point)
    {}

    ITrafficParticipantItem* createItem(const QRectF& rect) {
        return new PedestrianItem(rect);
    }
};

#endif // PEDESTRIAN_H
